@echo off
cls

set CELL_SDK=/c/usr/local/cell
set WIN_PS3SDK=C:/PSDK3v2
set PATH=%WIN_PS3SDK%/mingw/msys/1.0/bin;%CELL_SDK%/host-win32/sn/bin;

make

pause