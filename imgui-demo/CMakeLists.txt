cmake_minimum_required(VERSION 3.0)
project(imgui_demo CXX)

# set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    main.cpp
)

set(IMGUI_SOURCES
)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(imgui_demo ${SOURCES} ${IMGUI_SOURCES})
target_include_directories(imgui_demo PUBLIC ${IMGUI_DIR})
target_link_libraries(imgui_demo PRIVATE OpenGL::GL glfw)
