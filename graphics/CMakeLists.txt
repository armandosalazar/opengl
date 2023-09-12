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

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		"${CMAKE_CURRENT_SOURCE_DIR}/assets"
		"$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets")

target_link_libraries(${PROJECT_NAME}
	GLEW::GLEW
	glfw
	nanovg)