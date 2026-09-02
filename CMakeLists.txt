cmake_minimum_required(VERSION 3.16)

project(NovaEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
find_package(OpenGL REQUIRED)

add_executable(NovaEngine
    src/main.cpp
    src/window.cpp
    src/filemanagement.cpp
    src/glad.cpp
    src/math.cpp
    src/model.cpp
    src/shader.cpp
)

target_include_directories(NovaEngine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
)

target_link_directories(NovaEngine PRIVATE
    ${SDL2_LIBRARY_DIRS}
)

target_link_libraries(NovaEngine PRIVATE
    ${SDL2_LIBRARIES}
    OpenGL::GL
)

target_compile_options(NovaEngine PRIVATE
    ${SDL2_CFLAGS_OTHER}
)
