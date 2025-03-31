//
// Created by Tomáš Tatyrek on 24.03.2025.
//

#include <iostream>
#include "SDL3/SDL.h"
#include "Game.h"

#define SNAKE_BLOCK_SIZE 20
#define WINDOW_WIDTH_IN_BLOCKS 40
#define WINDOW_HEIGHT_IN_BLOCKS 30
#define WINDOW_TITLE "SDL Snake"
#define SDL_INIT_FLAGS (SDL_INIT_VIDEO)
#define SDL_WINDOW_FLAGS 0
#define SNAKE_TEMPO 150
#define STARTING_FOOD 5

int main() {
	std::cout << "Snake game started!\n";

	//Set game properties
	const GameProperties properties {
		SNAKE_BLOCK_SIZE,
		WINDOW_WIDTH_IN_BLOCKS,
		WINDOW_HEIGHT_IN_BLOCKS,
		SNAKE_TEMPO,
		STARTING_FOOD,
		WINDOW_TITLE,
		SDL_INIT_FLAGS,
		SDL_WINDOW_FLAGS};

	//Start the game
	Game game {properties};

	return 0;
}