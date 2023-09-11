cmake_minimum_required(VERSION 3.15)
project(Graphics CXX)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

set(NANOVG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/nanovg")

add_subdirectory(${NANOVG_DIR})

add_executable(${PROJECT_NAME}
	"src/main.cpp"
	"src/graphics.h"
	"src/graphics.cpp")

target_compile_definitions(${PROJECT_NAME}
	PUBLIC
	IMGUI_IMPL_OPENGL_LOADER_GLEW)
target_link_libraries(${PROJECT_NAME}
	nanovg
	GLEW::GLEW
	glfw)