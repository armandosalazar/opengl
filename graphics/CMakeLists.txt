cmake_minimum_required(VERSION 3.15)
project(Graphics CXX)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(Graphics "main.cpp" "graphics.h")
target_link_libraries(Graphics GLEW::GLEW glfw)