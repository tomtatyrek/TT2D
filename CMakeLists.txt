cmake_minimum_required(VERSION 3.16)
project(TT2D LANGUAGES C CXX VERSION 0.1.0)



# Prevents shared libraries
set(BUILD_SHARED_LIBRARIES OFF)



# Decide to build shared or static libraries
option(TT2D_SHARED "Whether or not to build shared TT2D library" OFF)
option(TT2D_STATIC "Whether or not to build static TT2D library" ON)



# TT2D Library:

# Sets target name depending on the type of library a creates the target
if(TT2D_STATIC)
  set(TT2D_TARGET_NAME "TT2D-static")
  add_library(${TT2D_TARGET_NAME} STATIC)
elseif(TT2D_SHARED)
  set(TT2D_TARGET_NAME "TT2D-shared")
  add_library(${TT2D_TARGET_NAME} SHARED)
else()
  set(TT2D_TARGET_NAME "TT2D")
  add_library(${TT2D_TARGET_NAME})
endif()

# Adds sources to TT2D library
target_sources(${TT2D_TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/TT2D.cpp)

# Adds include directory to TT2D library
target_include_directories(${TT2D_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Adds dependencies:
add_subdirectory(vendored/SDL)
add_subdirectory(vendored/SDL_image)

# Sets dependency libraries types
set(SDL_STATIC ${TT2D_STATIC})
set(SDL_SHARED ${TT2D_SHARED})

# Links dependencies to TT2D library
target_link_libraries(${TT2D_TARGET_NAME} SDL3::SDL3 SDL3_image::SDL3_image)

# Adds TT2D::TT2D alias
add_library(TT2D::TT2D ALIAS ${TT2D_TARGET_NAME})



# Examples:
option(BUILD_EXAMPLES "Whether or not to build examples" ON)

if (BUILD_EXAMPLES)

    message(STATUS "Building examples...")
    
    # TT2D_Example1 executable:
    add_executable(TT2D_Example1 examples/example1/main.cpp)
    target_link_libraries(TT2D_Example1 TT2D::TT2D)

endif()