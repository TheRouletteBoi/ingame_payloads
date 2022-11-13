@echo off
cls

set PS3DEV=/c/usr/local/cell/host-win32
set WIN_PS3SDK=C:/PSDK3v2
set PATH=%WIN_PS3SDK%/mingw/msys/1.0/bin;%PS3DEV%/ppu/bin;

cd GTAVPayload
make

pause