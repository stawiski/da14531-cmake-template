@echo off

@set BUILD=build

@rem Cleanup build directory
@if exist %BUILD% (
    @echo Cleaning
    rmdir /Q /S %BUILD%

    @if ERRORLEVEL 1 (
        @echo Cleaning build directory failed
        @goto exit
    )
)

mkdir %BUILD%

@if ERRORLEVEL 1 (
    @echo Creating build directory failed
    @goto exit
)

@if "%~1" == "" (
    @echo Missing GCC_TOOLCHAIN_PATH
    @goto exit
)

@if "%~2" == "" (
    @echo Missing DIALOG_SDK_PATH
    @goto exit
)

@rem Call CMake with arguments
cmake -DDEVICE_NAME=DA14531_App -DCMAKE_BUILD_TYPE=DEBUG -DCMAKE_TOOLCHAIN_FILE=gcc/arm-none-eabi.cmake -DGCC_TOOLCHAIN_PATH=%1 -DDIALOG_SDK_PATH=%2 -G "MSYS Makefiles" -S . -B %BUILD%

@if ERRORLEVEL 1 (
    @echo CMake failed
    @goto exit
)

cd %BUILD%
make -j 7

@if ERRORLEVEL 1 (
    @echo Make failed
    @goto exit
)

:exit
    @echo Exit.
