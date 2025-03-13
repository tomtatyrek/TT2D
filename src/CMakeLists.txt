project(TT2D)

add_library(TT2D TT2D.cpp)
add_library(TT2D::TT2D ALIAS TT2D)

target_include_directories(TT2D PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)