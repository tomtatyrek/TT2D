cmake_minimum_required(VERSION 3.16)
project(TT2D LANGUAGES C CXX VERSION 0.1.0)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(vendored)

option(BUILD_EXAMPLES "Whether or not to build examples" ON)

if (BUILD_EXAMPLES)
    message(STATUS "Building examples...")
    add_subdirectory(example)
endif()