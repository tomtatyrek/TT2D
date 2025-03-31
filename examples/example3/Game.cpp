//
// Created by Tomáš Tatyrek on 29.03.2025.
//

#include "Game.h"
#include "Log.h"

#include <iostream>
#include <thread>

GameProperties::GameProperties(
		const int snakeBlockSize,
		const int widthInBlocks,
		const int heightInBlocks,
		const int snakeTempo,
		const char* title,
		const SDL_InitFlags initFlags,
		const SDL_WindowFlags windowFlags
		) : title(title), initFlags(initFlags), windowFlags(windowFlags) {
	this->snakeBlockSize = std::abs(snakeBlockSize);
	this->widthInBlocks = std::abs(widthInBlocks);
	this->heightInBlocks = std::abs(heightInBlocks);
	this->snakeTempo = std::abs(snakeTempo);
}

bool BlockCoords::operator==(const BlockCoords a) const {
	return x == a.x && y == a.y;
}


Game::Game(const GameProperties &properties) : gameProperties{properties} {

	//Fill arena with empty blocks
	clearArena();

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

	//Starts the game
	run();

}


Game::~Game() {
	//Destroys the SLD renderer and window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//Quits SDL
	SDL_Quit();
}

void Game::run() {

	//Sets up sleeping duration in between moves
	const auto sleepDuration = std::chrono::milliseconds(gameProperties.snakeTempo);

	//Game setup:
	snakeAlive = true;
	clearArena();
	createSnake();
	loadSnake();

	//Event and render loop
	while (gameRunning) {

		//Rendering
		renderArena();

		//Sleep
		std::this_thread::sleep_for(sleepDuration);

		//SDL event handling:
		handleEvents();

		if (snakeAlive) {

			deleteSnake();
			snakeAlive = !moveSnake(snakeDirection);
			loadSnake();

		} else {

			snakeAlive = true;
			clearArena();
			createSnake();
			loadSnake();

		}


	}

}

//Handles SDL events
void Game::handleEvents() {

	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_EVENT_QUIT:
				gameRunning = false;  //Stops the game
			break;

			//Key-pressing handling
			case SDL_EVENT_KEY_DOWN:
				switch (event.key.scancode) {
					case SDL_SCANCODE_LEFT:
						snakeDirection = LEFT;
					LOG_D("Pressed key LEFT");
					break;
					case SDL_SCANCODE_UP:
						snakeDirection = UP;
					LOG_D("Pressed key UP");
					break;
					case SDL_SCANCODE_RIGHT:
						snakeDirection = RIGHT;
					LOG_D("Pressed key RIGHT");
					break;
					case SDL_SCANCODE_DOWN:
						snakeDirection = DOWN;
					LOG_D("Pressed key DOWN");
					break;
					default:
						IGNORE(("Unhandled key event: %u\n", event.key.scancode));
				}
			break;
			default:
				IGNORE(("Unhandled event type: %u\n", event.type));
		}
	}

}

//Sets snake to the default position
void Game::createSnake(){
	//Default starting location of the snake
	snake = {
		{(gameProperties.widthInBlocks/2 + 2), (gameProperties.heightInBlocks/2)},
		{(gameProperties.widthInBlocks/2 + 1), (gameProperties.heightInBlocks/2)},
		{(gameProperties.widthInBlocks/2    ), (gameProperties.heightInBlocks/2)},
		{(gameProperties.widthInBlocks/2 - 1), (gameProperties.heightInBlocks/2)},
		{(gameProperties.widthInBlocks/2 - 2), (gameProperties.heightInBlocks/2)}
	};
}

//Renders the arena to the screen
void Game::renderArena() const {

	//Renders the whole screen black
	SDL_SetRenderDrawColor(renderer, 0, 0, 0 , 255);
	SDL_RenderClear(renderer);

	// Outer loop iterates through the outer vector (rows)
	for (int x = 0; x < arena.size(); x++) {

		// Inner loop iterates through each inner vector (columns)
		for (int y = 0; y < arena.size(); y++) {

			//Set color according to the block state
			const auto [r, g, b, a] = getStateColor(arena[x][y]);
			SDL_SetRenderDrawColor(renderer, r, g, b, a);

			//Render a rectangle with specified color
			const SDL_FRect rect = getRectFromBlock({x, y});
			SDL_RenderFillRect(renderer, &rect);

		}
	}

	//Presents the rendered screen
	SDL_RenderPresent(renderer);

}

//Retuns an SDL_FRect, which corresponds to the specified BlockCoords
SDL_FRect Game::getRectFromBlock(const BlockCoords blockCoords) const {
	return {static_cast<float>(blockCoords.x * gameProperties.snakeBlockSize),
		static_cast<float>(blockCoords.y * gameProperties.snakeBlockSize),
		static_cast<float>(gameProperties.snakeBlockSize),
		static_cast<float>(gameProperties.snakeBlockSize)};
}

//Returns the color of a block with specified state
SDL_Color Game::getStateColor(const BlockState state) {
	switch (state) {
		case EMPTY:
			return {0,0,0,255};
		case FOOD:
			return {0,0,255,0};
		case SNAKE_HEAD:
			return {255,255,0,255};
		case SNAKE_BODY:
			return {0,255,0,255};
		default:
			return {0,0,0,0};
	}
}

//Moves the snake in the specfied direction
bool Game::moveSnake(const Direction direction) {

	for (auto i = snake.size() - 1; i >= 1; --i) {
		snake[i] = snake[i-1];
	}

	switch (direction) {
		case LEFT:
			snake[0] = {snake[1].x - 1, snake[1].y};
			break;
		case UP:
			snake[0] = {snake[1].x, snake[1].y - 1};
			break;
		case RIGHT:
			snake[0] = {snake[1].x + 1, snake[1].y};
			break;
		case DOWN:
			snake[0] = {snake[1].x, snake[1].y + 1};
			break;
	}

	//Checks for collisions of the snake with itself
	for (auto i = 3; i < snake.size(); ++i) {
		if (snake[i] == snake[0]) return true;
	}

	return false;
}

//Loads the blocks, which are part of the snake to arena
void Game::loadSnake() {

	arena[snake[0].x][snake[0].y] = SNAKE_HEAD;

	for (int i = 1; i < snake.size(); i++) {

		arena[snake[i].x][snake[i].y] = SNAKE_BODY;

	}

}

//Sets all snake blocks in the arena to EMPTY
void Game::deleteSnake() {
	for (auto& i : arena) {
		for (auto& j : i) {
			if (j == SNAKE_HEAD || j == SNAKE_BODY) {
				j = EMPTY;
			}
		}
	}
}

//Sets all blocks in arena to EMPTY
void Game::clearArena() {
	arena = {static_cast<long long unsigned int>(gameProperties.widthInBlocks), {static_cast<long long unsigned int>(gameProperties.heightInBlocks), EMPTY}};
}
