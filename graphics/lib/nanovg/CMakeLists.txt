project(nanovg C)

set(SOURCES
    "src/nanovg.c"
    "src/nanovg.h"
    "src/nanovg_gl.h"
)

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)