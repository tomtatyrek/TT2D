project(TT2D)

add_subdirectory(SDL)
add_subdirectory(SDL_image)

target_link_libraries(TT2D PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)