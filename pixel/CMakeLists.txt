cmake_minimum_required(VERSION 3.23)
project(Program C)

set(CMAKE_C_STANDARD 11)

set(
	SOURCES
	main.c
	graphics.h
)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(Program ${SOURCES})

target_link_libraries(
	Program
	PRIVATE
	OpenGL::GL
	glfw
)
