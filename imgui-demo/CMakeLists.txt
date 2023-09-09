cmake_minimum_required(VERSION 3.15)
project(ImGui-Demo CXX)

find_package(imgui REQUIRED)
find_package(glew REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/imgui_impl_glfw.cpp
    src/imgui_impl_glfw.h
    src/imgui_impl_opengl3.cpp
    src/imgui_impl_opengl3.h
    src/imgui_impl_opengl3_loader.h
    )

target_compile_definitions(${PROJECT_NAME} PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLEW)
target_link_libraries(${PROJECT_NAME}
    imgui::imgui
    GLEW::GLEW
    glfw 
    )
