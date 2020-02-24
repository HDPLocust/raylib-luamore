<img align="left" src="logo/raylib_luamore_256x256.png" width=256>

A Lua binding and extension for [Raylib](https://www.raylib.com) ([git](https://github.com/raysan5/raylib)).

Raylib-luamore is shared library for Lua and LuaJIT (current build is for luajit). Check [Build](build) for reference.

# Documentation
Source code is self-documented, but the extracted documentation is located in [Doc](doc) directory.
Functions is located in 

# Todo: 
* Finish main api;
* Add Physac;
* Add [Raygui](https://github.com/raysan5/raygui).

# Building
Currently this project for Windows and LuaJIT. So just run build.bat
Rebuilding the Raylib library is done using include/raylib/build_objects.bat (lib/raylib.a will updated).

# External stuff
This package provides with [LuaJITx86 2.1.0-beta2](http://luajit.org) and [TCC v0.9.27](https://bellard.org/tcc/) binaries for easier compiling and running.

# Binaries
Check [Build](build)

# Examples
Check [Build](build)

# License
Raylib-luamore is licensed under an zlib/libpng license.
*Copyright (c) 2020~2xxx [Snusmumriken](@HDPLocust)