cmake_minimum_required(VERSION 3.15)
project(Graphics CXX)

find_package(imgui REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(${PROJECT_NAME}
	"src/main.cpp"
	"lib/imgui_impl_glfw.cpp"
	"lib/imgui_impl_glfw.h"
	"lib/imgui_impl_opengl3.cpp"
	"lib/imgui_impl_opengl3.h"
	"lib/imgui_impl_opengl3_loader.h"
	"src/graphics.h"
	"src/graphics.cpp")

target_link_libraries(${PROJECT_NAME}
	PRIVATE
	imgui::imgui
	GLEW::GLEW
	glfw)