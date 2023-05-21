#!/bin/bash

BUILD_TYPE=$1

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

cd "$BUILD_DIR"	

echo "Clean"
rm -rf CMakeFiles Makefile CMakeCache.txt cmake_install.cmake

echo "Run cmake"
cmake  -DCMAKE_BUILD_TYPE="$BUILD_TYPE" ../

echo "Run make"
make