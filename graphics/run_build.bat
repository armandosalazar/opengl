REM conan profile detect

conan install . --build=missing
cmake --preset conan-default
cmake --build --preset conan-release
cd build\Release
.\Graphics.exe
