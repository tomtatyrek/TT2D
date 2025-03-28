//
// Created by Tomáš Tatyrek on 17/03/2025.
//

#include <iostream>

#include "Game.h"
#include "SDL3/SDL.h"

#define WINDOW_FLAGS (SDL_WINDOW_RESIZABLE)

int main() {

	std::cout << "Ahoj!";

	constexpr WindowProperties windowProperties {"Sus", 800, 600, WINDOW_FLAGS};

	const Game game (windowProperties, SDL_INIT_VIDEO);

	game.run();

	return 0;
}