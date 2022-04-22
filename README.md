# Building

---
## Linux

Requirements:

- ######  Ninja Builder

​	To build this project on Linux, you need **Ninja** builder in your machine. If you don't, in Ubuntu, you can get it by: 

	$ sudo apt-get install ninja-build

​	In order to get ninja-build in other distros you can find it on [this link](https://ninja-build.org/)

- ###### CMake (3.14.0 at least)

​	You also need CMake **(At Least 3.14.0)** to Build the project. If you don't, you can get it by:

```
$ wget https://github.com/Kitware/CMake/releases/download/v3.21.4/cmake-3.21.4.tar.gz
$ tar zxvf cmake-3.21.4.tar.gz
$ cd cmake-3.21.4
$ sudo ./bootstrap
$ sudo make
$ sudo make install
```

Building:

​	Once you have these dependencies, just run the script and you're good to go:

```
$ cd Bootstrap ; chmod +x ./bootstrap-codelite-linux.sh ; ./bootstrap-codelite-linux.sh
```
**NOTE**: If you don't wan't to use **CodeLite** as your IDE, feel free to change it by choosing other script.

---

## Windows

Requirements:

- ###### Microsoft Visual Studio 2019
- ###### CMake (3.14.0 at least)

Building:

​	To build for windows, just execute the ***batch*** file inside **Bootstrap** folder:

```
Bootstrap\bootstrap-windows-vsstudio
```

---

## NOTES: 

## Long Term features possibilities:

~> **Scripting Language**: Lua, Python or **Go**
~> **Unit Tests Framework**: Microsoft Unit Testing Framework, **GoogleTest**
~> **API Support:** **Vulcan**, **OpenGL**, DirectX

