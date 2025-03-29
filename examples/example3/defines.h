//
// Created by Tomáš Tatyrek on 29.03.2025.
//

#ifndef DEFINES_H
#define DEFINES_H

#include "SDL3/SDL.h"

#define DEFAULT_SNAKE_TEMPO 1000

//Define snake block states
enum BlockState : char {
	EMPTY,
	FOOD,
	SNAKE_HEAD,

	//Direction in body states signifies the next body/block of the snake towards the head
	SNAKE_BODY_LEFT,
	SNAKE_BODY_UP,
	SNAKE_BODY_RIGHT,
	SNAKE_BODY_DOWN
};

//Define snake head direction
enum Direction : char {
	RIGHT,
	UP,
	LEFT,
	DOWN
};

//Game properties structure
struct GameProperties {

	int snakeBlockSize, widthInBlocks, heightInBlocks;
	const char* title;
	SDL_InitFlags initFlags;
	SDL_WindowFlags windowFlags;

	GameProperties() = delete;
	GameProperties(
		int snakeBlockSize,
		int widthInBlocks,
		int heightInBlocks,
		const char* title,
		SDL_InitFlags initFlags,
		SDL_WindowFlags windowFlags);

};

//Block coordinates structure
struct BlockCoords {
	int x, y;
};


#endif //DEFINES_H
