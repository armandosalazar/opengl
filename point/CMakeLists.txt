cmake_minimum_required(VERSION 3.25)
project(open_gl)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(open_gl main.c)

target_link_libraries(open_gl OpenGL::GL glfw)
