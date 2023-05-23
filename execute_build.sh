#!/bin/bash

print_message()
{
	MESSAGE=$1
	LEVEL=$2
	NO_COLOR='\e[0m'
	MSG_COLOR=$NO_COLOR
	if [ "$LEVEL" == "error" ] || [ "$LEVEL" == "ERROR" ] ;then
			MSG_COLOR='\e[31m'
	elif [ "$LEVEL" == "info" ] || [ "$LEVEL" == "INFO" ] ;then
			MSG_COLOR='\e[33m'
	elif [ "$LEVEL" == "ok" ] || [ "$LEVEL" == "OK" ] ;then
			MSG_COLOR='\e[32m'
	fi
	echo
	echo -e "${MSG_COLOR}$MESSAGE${NO_COLOR}"
	echo
}

test_url()
{
	URL=$1
	if wget -q --method=HEAD "$URL";
	then
		return 0
	else
		return 1
	fi
	return 1
}

clone_repo()
{
	GIT_URL=$1
	DEST_FOLDER=$2
	ACTUAL_DIR="$PWD"
	test_url "$GIT_URL"
	URL_RET=$?
	if [ "$URL_RET" -ne 0 ];then
		print_message "Repo url $GIT_URL not valid" error
		return 1
	fi
	print_message "Cloning repo $GIT_URL to $DEST_FOLDER..." info
	git clone "$GIT_URL" "$DEST_FOLDER" 1>/dev/null 2>/dev/null
	cd "$DEST_FOLDER"
	# Get latest tag name
	latestTag=$(git describe --tags `git rev-list --tags --max-count=1`)
	# Checkout latest tag
	git checkout $latestTag 1>/dev/null 2>/dev/null
	cd "$ACTUAL_DIR"
	return 0
}

CONF_FILE=$1
CONTRIB_FOLDER="contrib"
ST_CUBE_DIR="st_cube"
OBKO_GIT_REPO="https://github.com/ObKo/stm32-cmake"
OBKO_CMAKE_DIR="./$CONTRIB_FOLDER/obko_stm32cmake"
SRC_DIR="$PWD"
CMAKE_TOOLCHAIN="$OBKO_CMAKE_DIR/cmake/stm32_gcc.cmake"

if [ ! -z "$CONF_FILE" ] && [ -f "$CONF_FILE" ];then
	source "$CONF_FILE"
	STM_FAMILY=$(echo "$STM_FAMILY" | awk '{ print toupper($0) }')
	STM_TYPE=$(echo "$STM_TYPE" | awk '{ print toupper($0) }')
else
	print_message "Config file not present" error
	exit 1
fi

if [ ! -d "$OBKO_CMAKE_DIR" ];then
	print_message "Checking Obko stm32_cmake repo" info
	clone_repo "$OBKO_GIT_REPO" "$OBKO_CMAKE_DIR"
	RET=$?
	if [ "$RET" -eq 1 ];then
		exit 1
	fi
fi

ST_CUBE_PATH="./$ST_CUBE_DIR/STM32Cube$STM_FAMILY"

if [ ! -d "$ST_CUBE_PATH" ];then
	print_message "Checking ST Cube Driver repo for family $STM_FAMILY" info
	if [ -z "$CUBE_GIT_REPO" ]; then
		print_message "Insert a url for STCube Driver" error
		exit 1
	fi

	ST_CUBE_PATH="./$ST_CUBE_DIR/STM32Cube$STM_FAMILY"

	clone_repo "$CUBE_GIT_REPO" "$ST_CUBE_PATH"
	RET=$?
	if [ "$RET" -eq 1 ];then
		exit 1
	fi
fi

if [ -z "$BUILD_TYPE" ];then
	BUILD_DIR=build_Debug
	BUILD_TYPE=Debug
else
	if [ "$BUILD_TYPE" == "debug" ];then
		BUILD_DIR=build_Debug
		BUILD_TYPE=Debug
	elif [ "$BUILD_TYPE" == "release" ]; then
		BUILD_DIR=build_Release
		BUILD_TYPE=Release
	else
		BUILD_DIR=build_Debug
		BUILD_TYPE=Debug
	fi
fi

if [ -d "$BUILD_DIR" ];then
	print_message "Clean build dir" info
	rm -rf "$BUILD_DIR"
fi


print_message "Build target in \"$BUILD_TYPE\" mode" info

print_message "Build folder is \"$BUILD_DIR\"" info

mkdir -p "$BUILD_DIR"


cd "$BUILD_DIR"	

print_message "Run cmake" info
cmake -DCMAKE_TOOLCHAIN_FILE="$CMAKE_TOOLCHAIN" -DSTM32_CUBE_"$STM_FAMILY"_PATH="$ST_CUBE_PATH" -DSTM32_FAMILY="$STM_FAMILY" -DSTM32_TYPE="$STM_TYPE" -DCMAKE_BUILD_TYPE="$BUILD_TYPE" "$SRC_DIR" #../

print_message "Run make" info
make

print_message "All done!" ok

print_message "Exporting compile_commands.json" info

cd "$SRC_DIR"
mv "$BUILD_DIR/compile_commands.json" "$SRC_DIR" 2>/dev/null
MV_RET=$?

if [ "$MV_RET" -eq 0 ];then
	print_message "Export done!" ok
else
	print_message "File not exported" error
fi