cmake_minimum_required(VERSION 3.16)
project(TT2D LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)

add_library(TT2D STATIC src/TT2D.cpp)

add_subdirectory(vendored/SDL)
add_subdirectory(vendored/SDL_image)

target_link_libraries(TT2D SDL3::SDL3 SDL3_image::SDL3_image)