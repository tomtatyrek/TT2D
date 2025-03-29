//
// Created by Tomáš Tatyrek on 29.03.2025.
//

#include "Game.h"

#include <iostream>

GameProperties::GameProperties(
		const int snakeBlockSize,
		const int widthInBlocks,
		const int heightInBlocks,
		const char* title,
		const SDL_InitFlags initFlags,
		const SDL_WindowFlags windowFlags
		) : title(title), initFlags(initFlags), windowFlags(windowFlags) {
	this->snakeBlockSize = std::abs(snakeBlockSize);
	this->widthInBlocks = std::abs(widthInBlocks);
	this->heightInBlocks = std::abs(heightInBlocks);
}



Game::Game(const GameProperties &properties) : gameProperties{properties} {

	//Fill arena with empty blocks
	arena = {static_cast<long long unsigned int>(gameProperties.widthInBlocks), {static_cast<long long unsigned int>(gameProperties.heightInBlocks), EMPTY}};

	//Initialize SDL
	if (!SDL_Init(gameProperties.initFlags)) {
		std::cerr << "Error while initializing SDL: " << SDL_GetError();
	}

	//Create a hidden window
	window = SDL_CreateWindow(gameProperties.title,
	                          gameProperties.widthInBlocks * gameProperties.snakeBlockSize,
	                          gameProperties.heightInBlocks * gameProperties.snakeBlockSize,
	                          gameProperties.windowFlags | SDL_WINDOW_HIDDEN);

	//Create a renderer for that window
	renderer = SDL_CreateRenderer(window, nullptr);

	//Shows the windows unless it has the SDL_WINDOW_HIDDEN flag
	if ((gameProperties.windowFlags & SDL_WINDOW_HIDDEN) == 0) {
		SDL_ShowWindow(window);
	}

	run();
}


Game::~Game() {
	//Destroys the SLD renderer and window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//Quits SDL
	SDL_Quit();
}



inline void Game::run() {

	bool quit = false;

	//Game loop
	while (!quit) {

		//SDL event handling:
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_EVENT_QUIT:
					quit = true;
					break;
				default:
					std::cerr << "Unhandled event type: " << event.type << "\n";
			}
		}

		//Rendering:
		renderArena();

	}

}



void Game::createSnake(){

	//Array with the default starting location of the snake
	const BlockCoords startingSnakeLocations[] = {
		{(gameProperties.widthInBlocks/2), (gameProperties.heightInBlocks/2)},
		{(gameProperties.widthInBlocks/2 - 1), (gameProperties.heightInBlocks/2)},
		{(gameProperties.widthInBlocks/2 - 2), (gameProperties.heightInBlocks/2)}
	};

	arena[startingSnakeLocations[0].x][startingSnakeLocations[0].y] = SNAKE_HEAD;
	arena[startingSnakeLocations[1].x][startingSnakeLocations[1].y] = SNAKE_BODY_LEFT;
	arena[startingSnakeLocations[2].x][startingSnakeLocations[2].y] = SNAKE_BODY_LEFT;

}

void Game::renderArena() const {

	//Renders the whole screen black
	SDL_SetRenderDrawColor(renderer, 0, 0, 0 , 255);
	SDL_RenderClear(renderer);

	//Keeps track of current coordinates
	int x = 0, y = 0;

	// Outer loop iterates through the outer vector
	for (const auto & i : arena) {

		// Inner loop iterates through each inner vector
		for (const auto & j : i) {

			//Set color according to the block state
			const auto [r, g, b, a] = getStateColor(j);
			SDL_SetRenderDrawColor(renderer, r, g, b, a);

			//Render a rectangle with specified color
			const SDL_FRect rect = getRectFromBlock({x, y});
			SDL_RenderFillRect(renderer, &rect);

			y++;
		}
		x++;
	}

	//Presents the rendered screen
	SDL_RenderPresent(renderer);

}

SDL_FRect Game::getRectFromBlock(const BlockCoords blockCoords) const {
	return {static_cast<float>(blockCoords.x * gameProperties.snakeBlockSize),
		static_cast<float>(blockCoords.y * gameProperties.snakeBlockSize),
		static_cast<float>(gameProperties.snakeBlockSize),
		static_cast<float>(gameProperties.snakeBlockSize)};
}

SDL_Color Game::getStateColor(const BlockState state) {
	switch (state) {
		case EMPTY:
			return {0,0,0,255};
			break;
		case FOOD:
			return {0,0,255,0};
		break;
		case SNAKE_HEAD:
			return {255,255,0,255};
		break;
		case SNAKE_BODY_LEFT:
		case SNAKE_BODY_UP:
		case SNAKE_BODY_RIGHT:
		case SNAKE_BODY_DOWN:
			return {0,255,0,255};
		break;
		default:
			return {0,0,0,0};
	}
}

void Game::moveSnake(Direction direction) {

	//TODO: Complete starting here!

}
