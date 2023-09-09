cmake_minimum_required(VERSION 3.5)
project(Program C)

# set(CMAKE_C_STANDARD 11)

set(SOURCES
	main.c
	graphics.h
)

# find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

add_executable(${PROJECT_NAME}
	${SOURCES}
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
	# OpenGL::GL
	GLEW::GLEW
	glfw
)
