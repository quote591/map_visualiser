# map\_visualiser

## Dependancies
- MinGW
- Depends on GLFW library
- CMake version >= 3.20.0
- Ninja build system

### GLFW
Head over to `https://www.glfw.org/download.html` and get the windows
pre-compiled binaries. If you are on linux, install via package manager or 
compile from source.

For the windows user, get the libs from the MinGW folder and place them in
3rdParty/GLFW/win\_libs. Otherwise get the vs versions and compile with MSVC.

### Ninja
Ninja build system can be installed in windows with spool

# Installation
To compile and build use the following for MinGW users
```bash
cmake --preset default
cmake --build --preset default
```
Default is a debug build using the Ninja generator

