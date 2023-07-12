#!/bin/bash

print_message() {
    declare -A colors
    colors["error"]='\e[31m'
    colors["info"]='\e[33m'
    colors["warning"]='\e[1;33m'
    colors["ok"]='\e[32m'
    NO_COLOR='\e[0m'

    MESSAGE=$1
    LEVEL=$(echo "$2" | awk '{print tolower($0)}')

    MSG_COLOR=${colors[$LEVEL]}

    echo
    echo -e "${MSG_COLOR}$MESSAGE${NO_COLOR}"
    echo
}

test_url() {
    URL=$1
    if wget -q --method=HEAD "$URL"; then
        return 0
    else
        return 1
    fi
}

clone_repo() {
    GIT_URL=$1
    DEST_FOLDER=$2
    ACTUAL_DIR="$PWD"
    test_url "$GIT_URL"
    URL_RET=$?
    if [ "$URL_RET" -ne 0 ]; then
        print_message "Repo url $GIT_URL not valid" error
        return 1
    fi
    print_message "Cloning repo $GIT_URL to $DEST_FOLDER..." info
    git clone "$GIT_URL" "$DEST_FOLDER" 1>/dev/null 2>/dev/null
    cd "$DEST_FOLDER" || return 1
    # Get latest tag name
    latestTag=$(git describe --tags "$(git rev-list --tags --max-count=1)")
    # Checkout latest tag
    git checkout "$latestTag" 1>/dev/null 2>/dev/null
    cd "$ACTUAL_DIR" || return 1
    return 0
}

get_board() {
    MAIN_FOLDER=$1
    directories=()
    while IFS= read -r -d '' dir; do
        name=$(basename "$dir")
        directories+=("$name")
    done < <(find "$MAIN_FOLDER" -mindepth 1 -type d -print0)

    select PROJECT_BOARD in "${directories[@]}"; do
        if [[ -n $PROJECT_BOARD ]]; then
            print_message "Hai selezionato: $PROJECT_BOARD	" ok
            break
        else
            echo "Opzione non valida. Riprova."
        fi
    done
}

CONF_FILE=$1
CLEAN_BUILD=$2
CONTRIB_FOLDER="contrib"
ST_CUBE_DIR="st_cube"
OBKO_GIT_REPO="https://github.com/ObKo/stm32-cmake"
OBKO_CMAKE_DIR="./$CONTRIB_FOLDER/obko_stm32cmake"
SRC_DIR="$PWD"
CMAKE_TOOLCHAIN="$OBKO_CMAKE_DIR/cmake/stm32_gcc.cmake"
BOARDS_FOLDER="./boards_stm32"

if [ ! -z "$CLEAN_BUILD" ] && [ "$CLEAN_BUILD" == "clean" ]; then
    rm ".project.board"
fi

if [ ! -f ".project.board" ]; then
    print_message "Selezionare una board per il progetto" info
    get_board "$BOARDS_FOLDER"
    echo "PROJECT_BOARD=$PROJECT_BOARD" > .project.board
else
    source ".project.board"
fi

if [ ! -z "$CONF_FILE" ] && [ -f "$CONF_FILE" ]; then
    source "$CONF_FILE"
    if [ -z "$STM_FAMILY" ] || [ -z "$STM_TYPE" ] || [ -z "$PROJECT_BOARD" ]; then
        print_message "One or more field of the config file \"$CONF_FILE\" are empty" error
        exit 1
    fi
    STM_FAMILY=$(echo "$STM_FAMILY" | awk '{ print toupper($0) }')
    STM_TYPE=$(echo "$STM_TYPE" | awk '{ print toupper($0) }')
    if [ ! -d "$BOARDS_FOLDER/$PROJECT_BOARD" ]; then
        print_message "The board folder for \"$PROJECT_BOARD\" doesn't exist" error
        exit 1
    fi
    print_message "STM Family selected: $STM_FAMILY" info
    print_message "STM Type selected: $STM_TYPE" info
    print_message "Board selected: $PROJECT_BOARD" info
else
    print_message "Config file not present" error
    exit 1
fi

if [ ! -d "$OBKO_CMAKE_DIR" ]; then
    print_message "Checking Obko stm32_cmake repo" info
    clone_repo "$OBKO_GIT_REPO" "$OBKO_CMAKE_DIR"
    RET=$?
    if [ "$RET" -eq 1 ]; then
        exit 1
    fi
fi

ST_CUBE_PATH="./$ST_CUBE_DIR/STM32Cube$STM_FAMILY"

if [ ! -d "$ST_CUBE_PATH" ]; then
    CUBE_GIT_REPO="https://github.com/STMicroelectronics/STM32Cube$STM_FAMILY.git"
    print_message "Checking ST Cube Driver repo for family $STM_FAMILY" info
    if [ -z "$CUBE_GIT_REPO" ]; then
        print_message "Insert a URL for STCube Driver" error
        exit 1
    fi

    ST_CUBE_PATH="./$ST_CUBE_DIR/STM32Cube$STM_FAMILY"

    clone_repo "$CUBE_GIT_REPO" "$ST_CUBE_PATH"
    RET=$?
    if [ "$RET" -eq 1 ]; then
        exit 1
    fi
fi

if [ -z "$BUILD_TYPE" ]; then
    BUILD_DIR="build_Debug_$STM_FAMILY"
    BUILD_TYPE=Debug
else
    if [ "$BUILD_TYPE" == "debug" ]; then
        BUILD_DIR="build_Debug_$STM_FAMILY"
        BUILD_TYPE=Debug
    elif [ "$BUILD_TYPE" == "release" ]; then
        BUILD_DIR="build_Release_$STM_FAMILY"
        BUILD_TYPE=Release
    else
        BUILD_DIR="build_Debug_$STM_FAMILY"
        BUILD_TYPE=Debug
    fi
fi

if [ -d "$BUILD_DIR" ]; then
    if [ ! -z "$CLEAN_BUILD" ] && [ "$CLEAN_BUILD" == "clean" ]; then
        print_message "Clean build dir" warning
        rm -rf "$BUILD_DIR"
        mkdir -p "$BUILD_DIR"
    else
        print_message "Build folder present" info
    fi
else
    mkdir -p "$BUILD_DIR"
fi

print_message "Build target in \"$BUILD_TYPE\" mode" info
print_message "Build folder is \"$BUILD_DIR\"" info

cd "$BUILD_DIR" || exit

print_message "Run cmake" info
cmake -DCMAKE_TOOLCHAIN_FILE="$CMAKE_TOOLCHAIN" \
      -DSTM32_CUBE_"$STM_FAMILY"_PATH="$ST_CUBE_PATH" \
      -DSTM32_FAMILY="$STM_FAMILY" \
      -DSTM32_TYPE="$STM_TYPE" \
      -DPROJECT_BOARD="$PROJECT_BOARD" \
      -DCMAKE_BUILD_TYPE="$BUILD_TYPE" "$SRC_DIR"

CMAKE_RET=$?
if [ "$CMAKE_RET" -ne 0 ]; then
    print_message "CMake FAILED" error
    exit 1
else
    print_message "CMake DONE!" ok
fi

print_message "Run make" info
make -j10

MAKE_RET=$?
if [ "$MAKE_RET" -ne 0 ]; then
    print_message "Build FAILED" error
    exit 1
else
    print_message "Build DONE!" ok
fi

print_message "Exporting compile_commands.json" info

cd "$SRC_DIR" || exit
mv "$BUILD_DIR/compile_commands.json" "$SRC_DIR" 2>/dev/null
MV_RET=$?

if [ "$MV_RET" -eq 0 ]; then
    print_message "Export DONE!" ok
else
    print_message "Export FAILED" error
fi
