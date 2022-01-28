# Merline-Engine

2D Engine C++ cross platform to make video games 

## Installation

### Linux

Using the Merline-Engine on linux require to install globally the SFML. Depending on your OS (Operating System)

for Debian: `sudo apt-get install libsfml-dev`

for Fedora: `sudo dnf install libsfml-devel`

You also need to install g++ (the C++ compiler):
Debian: `sudo apt-get install g++`
Fedora: `sudo dnf install g++`

You can work on the library or your project and compile it using the Makefile: `make` it should generate your binary and you can simply execute it

### Windows

Windows need different tools to work:

- Visual Studio (2019 prefered)
- CMake (at least 3.10)

You can work on the library or your project and compile it using the CMakeLists.txt:

`mkdir build && cd build`
`cmake ..`
`cmake --build . -j${core}` (replace ${core} with the number of core you want)

This should generate many files / folders in build and you can find your binary in: `build/Debug/` just copy/paste it at root and execute it 