//
// Created by Tomáš Tatyrek on 29.03.2025.
//

#ifndef TT2D_EX3_GAME_H
#define TT2D_EX3_GAME_H

#include "SDL3/SDL.h"
#include "defines.h"
#include <vector>


class Game {

	SDL_Window* window;
	SDL_Renderer* renderer;
	GameProperties gameProperties;
	std::vector<std::vector<BlockState>> arena;


public:

	Game() = delete;
	explicit Game(const GameProperties &properties);
	~Game();

private:
	inline void run();
	void createSnake();
	inline void renderArena() const;
	[[nodiscard]] SDL_FRect getRectFromBlock(BlockCoords blockCoords) const;
	void moveSnake(Direction direction);


	[[nodiscard]] static SDL_Color getStateColor(BlockState state);

};



#endif //TT2D_EX3_GAME_H
