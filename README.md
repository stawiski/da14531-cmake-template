# Introduction

The purpose of this repository is to provide a template to build firmware for DA14531 (Dialog's BLE microcontroller) under CMake with GCC for no code limits. This template integrates SEGGER RTT library for debug `printf`s through SWD using JLink debug probe (no need for hardware serial).

Author: Mikolaj Stawiski

# Requirements

To build the template you'll need:
- CMake >= 3.16 (download from https://cmake.org/download/)
- GCC for ARM (download from ARM's website https://developer.arm.com/). Recommended `gcc-arm-none-eabi-10-2020-q4-major`.
- Dialog SDK v.6.0.14.1114 (download from Dialog's website https://www.dialog-semiconductor.com/)
- make

Additionally if you want to run the firmware on the target you'll need:
- JLink debug probe
- JLink RTT Viewer (for displaying and logging `printf`s from the target)
- JLink Ozone debugger >= V3.22a
- Hardware based on DA14531 chip with SWD (e.g. DA14531 Basic USB kit)

Having installed CMake, and downloaded and unzipped GCC for ARM and required Dialog SDK, run `build-linux.sh` (Ubuntu/WSL/MacOS) or `build-windows.bat` (Windows) and supply it with paths to GCC and the SDK.

---
**NOTE for Windows**

You'll need `make` to compile the code, for which you might have to install MSYS.

---

# Running on target

Upon successful setup and build you'll get firmware files under `./build` directory. The firmware will come in few handy formats: binary, hex and elf.

If you want to debug the firmware using Ozone debugger, open `DA14531-debug.jdebug` with Ozone. The script will load the firmware into target's RAM and name your target's registers for nice debugging experience.

# Integration to VSCode

Below is an example of `tasks.json` for VSCode assuming you're on Linux, installed CMake, downloaded and unzipped GCC for ARM to `~/gcc-arm-none-eabi-10-2020-q4-major/`, and downloaded and unzipped Dialog SDK v.6.0.14.1114 to `~/dialog-sdk/`:
```
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build",
            "type": "shell",
            "command": "${workspaceFolder}/build-linux.sh",
            "args": [
                "~/gcc-arm-none-eabi-10-2020-q4-major/",
                "~/dialog-sdk"
            ],
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```
