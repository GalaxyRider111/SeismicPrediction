cmake_minimum_required(VERSION 3.14)
project(PaGUI C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Look for any raylib first

    set(MIN_RAYLIB_VERSION 5.0)  

    set(CMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY ON)
list(REMOVE_AT CMAKE_SYSTEM_PREFIX_PATH 0)


# ── Raylib – always fetched ─────────────────────────────────────
include(FetchContent)
FetchContent_Declare(raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.0
    GIT_SHALLOW    TRUE)
FetchContent_MakeAvailable(raylib)           # creates target 'raylib'

# ── Raygui – fetched next; it will reuse raylib_DIR we just set ─
FetchContent_Declare(raygui
    URL https://github.com/raysan5/raygui/archive/refs/tags/4.0.tar.gz)
FetchContent_MakeAvailable(raygui)           # creates target 'raygui'

add_library(raygui INTERFACE)
target_include_directories(raygui INTERFACE
    ${raygui_SOURCE_DIR}/src)  

# Our Project


add_executable(${PROJECT_NAME} main.c)
#set(raylib_VERBOSE 1)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib raygui) 



# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html") # Tell Emscripten to build an example.html file.
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
endif()