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
	echo -e "${MSG_COLOR}$MESSAGE${NO_COLOR}"
}

CONF_FILE=$1

if [ ! -z "$CONF_FILE" ] && [ -f "$CONF_FILE" ];then
	source "$CONF_FILE"
	STM_FAMILY=$(echo "$STM_FAMILY" | awk '{ print toupper($0) }')
	STM_TYPE=$(echo "$STM_TYPE" | awk '{ print toupper($0) }')
else
	print_message "[ERROR] Config file not present" error
	exit 1
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
	rm -rf "$BUILD_DIR"
fi

echo
print_message "Build target in \"$BUILD_TYPE\" mode" info
echo

echo
print_message "Build folder is \"$BUILD_DIR\"" info
echo


mkdir -p "$BUILD_DIR"

SOURCES_DIR="$PWD"

cd "$BUILD_DIR"	

echo
print_message "Run cmake" info
echo
cmake -DCMAKE_TOOLCHAIN_FILE="$CMAKE_TOOLCHAIN" -DSTM32_CUBE_"$STM_FAMILY"_PATH="$CUBE_DRIVERS" -DSTM32_FAMILY="$STM_FAMILY" -DSTM32_TYPE="$STM_TYPE" -DCMAKE_BUILD_TYPE="$BUILD_TYPE" "$SOURCES_DIR" #../

echo
print_message "Run make" info
echo
make

echo
print_message "All done!" ok
echo