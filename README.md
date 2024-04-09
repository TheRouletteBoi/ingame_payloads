# In Game Payloads For Playstation 3
load and inject payloads into memory to execute your mod menu.

# Project Structure
- `gtav-clang-cmake/`: Uses Clang 14.0.0 with CMake for compiling
- `gtav-g++-cmake/`: Uses GNU GCC 13.2.0 with CMake for compiling (requires linux)
- `gtav-sce-make/`: Uses Sony's SCE compiler with C++11 and make for compiling
 
# Requirements 
* [make](https://github.com/MiscPS3/MirrorSDK/releases/download/2023.09.17/psdk3-cobra-windows.tar.gz) Put in `C:\` Drive (Only used for `make` command line)
* [CMake](https://cmake.org/download/)
* Official Sony PS3 4.75+ SDK

# Loading
if you want to load your payload into a game you must use ps3mapi syscalls like ps3mapi_process_page_allocate and ps3mapi_create_process_thread in COBRA or MAMBA.

# Why use a payload instead of sprx?

PROS
* use up to date gcc toolchain compiler for latest C++ syntax
* low memory footprint which means you can add way more features than a sprx could 

CONS
* Inability to use built-in PS3 functions like cellMsgDialogOpen2 due to the unavailability of exports
