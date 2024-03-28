## ERROR: the binary needs to be 64bit with 32bit with address space. we might need to modify the toolchain??


1. go to `toolchain/toolchain.cmake`
2. change `set(triple powerpc64-eabi-freebsd-elfv1)` to `set(triple powerpc64-eabi-lv2-elfv1)`
3. ERROR!!!!!

```bash
.\gtav-clang-cmake\toolchain\bin\win-x86_64\clang++.exe -print-effective-triple
```
```
x86_64-pc-windows-msvc19.38.33128
```

```bash
.\gtav-clang-cmake\toolchain\bin\win-x86_64\clang++.exe -print-targets
```

```
Registered Targets:
    ppc32   - PowerPC 32
    ppc32le - PowerPC 32 LE
    ppc64   - PowerPC 64
    ppc64le - PowerPC 64 LE
```
