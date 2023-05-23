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

CONF_FILE=$1
CONTRIB_FOLDER="contrib"
ST_CUBE_DIR="st_cube"

if [ ! -z "$CONF_FILE" ] && [ -f "$CONF_FILE" ];then
	source "$CONF_FILE"
	STM_FAMILY=$(echo "$STM_FAMILY" | awk '{ print toupper($0) }')
	STM_TYPE=$(echo "$STM_TYPE" | awk '{ print toupper($0) }')
else
	print_message "Config file not present" error
	exit 1
fi

if [ ! -d "./$ST_CUBE_DIR/STM32Cube$STM_FAMILY" ];then
	print_message "Checking ST Cube Driver repo for family $STM_FAMILY" info
	if [ -z "$CUBE_GIT_REPO" ]; then
		print_message "Insert a url for STCube Driver" error
		exit 1
	fi
	test_url "$CUBE_GIT_REPO"
	URL_RET=$?
	if [ "$URL_RET" -ne 0 ];then
		print_message "Insert a valid url for STCube Driver" error
		exit 1
	fi

	print_message "Cloning repo $CUBE_GIT_REPO to $ST_CUBE_DIR/STM32Cube$STM_FAMILY..." info
	git clone "$CUBE_GIT_REPO" "./$ST_CUBE_DIR/STM32Cube$STM_FAMILY"
fi

CMAKE_TOOLCHAIN="./$CONTRIB_FOLDER/obko_stm32cmake/cmake/stm32_gcc.cmake"
CUBE_DRIVERS="./$ST_CUBE_DIR/STM32Cube$STM_FAMILY"

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
	rm -rf "$BUILD_DIR"
fi


print_message "Build target in \"$BUILD_TYPE\" mode" info

print_message "Build folder is \"$BUILD_DIR\"" info

mkdir -p "$BUILD_DIR"

SRC_DIR="$PWD"

cd "$BUILD_DIR"	

print_message "Run cmake" info
cmake -DCMAKE_TOOLCHAIN_FILE="$CMAKE_TOOLCHAIN" -DSTM32_CUBE_"$STM_FAMILY"_PATH="$CUBE_DRIVERS" -DSTM32_FAMILY="$STM_FAMILY" -DSTM32_TYPE="$STM_TYPE" -DCMAKE_BUILD_TYPE="$BUILD_TYPE" "$SRC_DIR" #../

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