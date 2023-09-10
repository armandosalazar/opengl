cmake_minimum_required(VERSION 3.15)
project(Graphics CXX)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(${PROJECT_NAME}
	"src/main.cpp"
	"src/Graphics.h"
	"src/Graphics.cpp")

target_link_libraries(${PROJECT_NAME}
	GLEW::GLEW
	glfw)