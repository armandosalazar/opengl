cmake_minimum_required(VERSION 3.25)
project(open_gl_pixel)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)


add_executable(open_gl_pixel main.c)

target_link_libraries(open_gl_pixel OpenGL::GL glfw m)