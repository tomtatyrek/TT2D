cmake_minimum_required(VERSION 3.16)
project(TT2D LANGUAGES C CXX VERSION 0.1.0)


# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



# Configure version file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/TT2DConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion)



# Decide to build shared or static libraries
option(TT2D_SHARED "Whether or not to build shared TT2D library" ON)
option(TT2D_STATIC "Whether or not to build static TT2D library" OFF)



# Determines whether examples should be built
option(BUILD_EXAMPLES "Whether or not to build examples" ON)

# Makes sure dlls are created in the same directory as the executable
if(BUILD_EXAMPLES AND TT2D_SHARED)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

endif()



# TT2D Library:

# Sets target name depending on the type of library, sets dependency targets' names and creates the target
if(TT2D_STATIC)
    set(BUILD_SHARED_LIBS OFF)
    set(TT2D_TARGET_NAME "TT2D-static")
    set(TT2D_SDL3_TARGET_NAME "SDL3::SDL3-static")
    set(TT2D_SDL3_IMAGE_TARGET_NAME "SDL3_image::SDL3_image-static")
    set(TT2D_SDL3_TTF_TARGET_NAME "SDL3_ttf::SDL3_ttf-static")
    add_library(${TT2D_TARGET_NAME} STATIC)
elseif(TT2D_SHARED)
    set(BUILD_SHARED_LIBS ON)
    set(TT2D_TARGET_NAME "TT2D-shared")
    set(TT2D_SDL3_TARGET_NAME "SDL3::SDL3-shared")
    set(TT2D_SDL3_IMAGE_TARGET_NAME "SDL3_image::SDL3_image-shared")
    set(TT2D_SDL3_TTF_TARGET_NAME "SDL3_ttf::SDL3_ttf-shared")
    add_library(${TT2D_TARGET_NAME} SHARED)
else()
    set(TT2D_TARGET_NAME "TT2D")
    set(TT2D_SDL3_TARGET_NAME "SDL3::SDL3")
    set(TT2D_SDL3_IMAGE_TARGET_NAME "SDL3_image::SDL3_image")
    set(TT2D_SDL3_TTF_TARGET_NAME "SDL3_ttf::SDL3_ttf")
    add_library(${TT2D_TARGET_NAME})
endif()

# Adds sources to TT2D library
target_sources(${TT2D_TARGET_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/TT2D.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/App.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Renderable.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Window.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Log.cpp
)

# Adds include directory to TT2D library
target_include_directories(${TT2D_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Adds SDL_image and SDL_tff directories:
add_subdirectory(${CMAKE_SOURCE_DIR}/vendored/SDL)
add_subdirectory(${CMAKE_SOURCE_DIR}/vendored/SDL_image)
add_subdirectory(${CMAKE_SOURCE_DIR}/vendored/SDL_ttf)

# Links dependencies to TT2D library
target_link_libraries(${TT2D_TARGET_NAME} ${TT2D_SDL3_TARGET_NAME} ${TT2D_SDL3_IMAGE_TARGET_NAME} ${TT2D_SDL3_TTF_TARGET_NAME})

# Adds TT2D::TT2D alias
add_library(TT2D::TT2D ALIAS ${TT2D_TARGET_NAME})



# Examples:

if (BUILD_EXAMPLES)

    message(STATUS "Building examples...")
    
    # TT2D_Example1 executable:
    add_executable(TT2D_Example1 examples/example1/main.cpp)
    target_link_libraries(TT2D_Example1 TT2D::TT2D)

    # SDLTesting executable:
    add_executable(SDLTesting examples/example2/main.cpp
            examples/example2/Game.cpp
            examples/example2/Game.h)
    target_link_libraries(SDLTesting ${TT2D_SDL3_TARGET_NAME} ${TT2D_SDL3_IMAGE_TARGET_NAME} ${TT2D_SDL3_TTF_TARGET_NAME})

    # SDL_Snake executable:
    add_executable(SDL_Snake
            examples/example3/main.cpp
            examples/example3/Game.cpp
            examples/example3/Game.h
            examples/example3/Snake.cpp
            examples/example3/Snake.h
            examples/example3/defines.h
    )
    target_link_libraries(SDL_Snake ${TT2D_SDL3_TARGET_NAME})

    # C_Snake executable:
    add_executable(C_Snake
            examples/example4/snake.c
    )
    target_link_libraries(C_Snake ${TT2D_SDL3_TARGET_NAME})

endif()