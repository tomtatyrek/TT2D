//
// Created by Tomáš Tatyrek on 29.03.2025.
//

#ifndef TT2D_EX3_GAME_H
#define TT2D_EX3_GAME_H

#include "SDL3/SDL.h"
#include <vector>

#define DEFAULT_SNAKE_TEMPO 1000

//Define snake block states
enum BlockState : char {
	EMPTY,
	FOOD,
	SNAKE_HEAD,
	SNAKE_BODY
};

//Define snake head direction
enum Direction : char {
	RIGHT = 0,
	UP,
	LEFT,
	DOWN
};

//Game properties structure
struct GameProperties {

	int snakeBlockSize, widthInBlocks, heightInBlocks, snakeTempo;
	const char* title;
	SDL_InitFlags initFlags;
	SDL_WindowFlags windowFlags;

	GameProperties() = delete;
	GameProperties(
		int snakeBlockSize,
		int widthInBlocks,
		int heightInBlocks,
		int snakeTempo,
		const char* title,
		SDL_InitFlags initFlags,
		SDL_WindowFlags windowFlags);

};

//Block coordinates structure
struct BlockCoords {
	int x, y;
	bool operator==(BlockCoords a) const;
};


class Game {

	SDL_Window* window;
	SDL_Renderer* renderer;
	GameProperties gameProperties;
	std::vector<std::vector<BlockState>> arena;
	std::vector<BlockCoords> snake;
	bool gameRunning = true;
	Direction snakeDirection = RIGHT;

public:

	Game() = delete;
	explicit Game(const GameProperties &properties);
	~Game();

private:
	void createSnake();
	inline void renderArena() const;
	[[nodiscard]] SDL_FRect getRectFromBlock(BlockCoords blockCoords) const;

	//Returns true if the snake colides with itself
	bool moveSnake(Direction direction);

	void loadSnake();
	void deleteSnake();
	inline void clearArena();
	inline void run();
	inline void handleEvents();
	[[nodiscard]] BlockCoords getBlockInDirection(BlockCoords current, Direction direction) const;


	[[nodiscard]] static SDL_Color getStateColor(BlockState state);

};



#endif //TT2D_EX3_GAME_H
