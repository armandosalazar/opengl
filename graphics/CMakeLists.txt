cmake_minimum_required(VERSION 3.10)
project(Graphics CXX)

find_package(imgui REQUIRED)

add_executable(Graphics main.cpp)

target_link_libraries(Graphics PRIVATE imgui::imgui)
