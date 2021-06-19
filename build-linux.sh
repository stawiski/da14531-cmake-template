#!/bin/sh

BUILD_DIR="build"

# Cleanup build directory
if [ -d "$BUILD_DIR" ]; then
    echo "Cleaning"
    rm -rf $BUILD_DIR
    if [ ! $? -eq 0 ]
    then
        echo "rm failed"
        exit 1
    fi
    mkdir $BUILD_DIR
    if [ ! $? -eq 0 ]
    then
        echo "mkdir failed"
        exit 1
    fi
fi

# Check two required arguments present
if [ "$#" -eq 2 ]; then
    cmake -DDEVICE_NAME=DA14531_App -DCMAKE_BUILD_TYPE=DEBUG -DCMAKE_TOOLCHAIN_FILE=gcc/arm-none-eabi.cmake -DGCC_TOOLCHAIN_PATH=$1 -DDIALOG_SDK_PATH=$2 -S . -B $BUILD_DIR
else
    echo "Arguments required."
    echo "Call this script providing: $0 GCC_TOOLCHAIN_PATH DIALOG_SDK_PATH"
    exit 1
fi

if [ ! $? -eq 0 ]
then
    echo "CMake failed"
    exit 1
fi

cd $BUILD_DIR
make -j 7

if [ ! $? -eq 0 ]
then
    echo "make failed"
    exit 1
fi
