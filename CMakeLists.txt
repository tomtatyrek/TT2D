cmake_minimum_required(VERSION 3.16)
project(TT2D LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)

add_library(TT2D STATIC src/TT2D.cpp
                        src/TT2D.h)

# Create an alias target that matches how you reference it in your project
add_library(TT2D::TT2D ALIAS TT2D)

# Specify include directories properly
target_include_directories(TT2D PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
)

set(SDL_OPENGLES OFF CACHE BOOL "Disable OpenGL ES support" FORCE)
set(SDL_OPENGL OFF CACHE BOOL "Disable OpenGL support" FORCE)
set(SDL_RENDERD3D11 OFF CACHE BOOL "Disable Direct3D 11 render driver" FORCE)
set(SDL_RENDERD3D12 OFF CACHE BOOL "Disable Direct3D 12 render driver" FORCE)

add_subdirectory(vendored/SDL)
add_subdirectory(vendored/SDL_image)

target_link_libraries(TT2D PUBLIC SDL3::SDL3 SDL3_image::SDL3_image)