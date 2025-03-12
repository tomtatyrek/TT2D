cmake_minimum_required(VERSION 3.16)
project(TT2D LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)

add_library(TT2D STATIC src/TT2D.cpp
                        src/TT2D.h
        src/math/Vector.cpp
        src/math/Vector.h
        src/defines.h
        src/App.cpp
        src/App.h
        src/util/Logger.cpp
        src/util/Logger.h
        src/render/Window.cpp
        src/render/Window.h)

add_library(TT2D::TT2D ALIAS TT2D)

target_include_directories(TT2D PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
)

set(SDL_OPENGLES OFF CACHE BOOL "Disable OpenGL ES support" FORCE)
set(SDL_OPENGL OFF CACHE BOOL "Disable OpenGL support" FORCE)
set(SDL_RENDERD3D11 OFF CACHE BOOL "Disable Direct3D 11 render driver" FORCE)
set(SDL_RENDERD3D12 OFF CACHE BOOL "Disable Direct3D 12 render driver" FORCE)

add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
add_subdirectory(vendored/SDL_image EXCLUDE_FROM_ALL)

target_link_libraries(TT2D PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)