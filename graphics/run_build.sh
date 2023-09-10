#!/bin/bash

conan install . --build=missing
cmake --preset conan-release
cmake --build --preset conan-release
cd build/Release
./Graphics