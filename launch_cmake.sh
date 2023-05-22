#!/bin/bash

CONF_FILE=$1

if [ ! -z "$CONF_FILE" ] && [ -f "$CONF_FILE" ];then
	source "$CONF_FILE"
	STM_FAMILY=$(echo "$STM_FAMILY" | awk '{ print toupper($0) }')
	STM_TYPE=$(echo "$STM_TYPE" | awk '{ print toupper($0) }')
else
	echo -e "\033[0;31mConfig file not present\033[0m"
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

echo -e "\033[0;32mBuild target in \"$BUILD_TYPE\" mode\033[0m"

mkdir -p "$BUILD_DIR"

SOURCES_DIR="$PWD"

cd "$BUILD_DIR"	

echo "Run cmake"
cmake -DCMAKE_TOOLCHAIN_FILE="$CMAKE_TOOLCHAIN" -DSTM32_CUBE_"$STM_FAMILY"_PATH="$CUBE_DRIVERS" -DSTM32_FAMILY="$STM_FAMILY" -DSTM32_TYPE="$STM_TYPE" -DCMAKE_BUILD_TYPE="$BUILD_TYPE" "$SOURCES_DIR" #../

echo "Run make"
make