//
// Created by Tomáš Tatyrek on 29.03.2025.
//

#ifndef TT2D_EX3_SNAKE_H
#define TT2D_EX3_SNAKE_H

#include "defines.h"
#include <vector>


class Snake {

	std::vector<BlockCoords> snakePosition;
	int tempo;	//The ammount of milliseconds the snake needs to move 1 block
	Direction snakeDirection;


public:
	Snake() = delete;
	Snake(int tempo, Direction startingDirection, const std::vector<BlockCoords>& snakeLocation);

	[[nodiscard]] BlockCoords getHead() const;
	[[nodiscard]] std::vector<BlockCoords> getBody() const;

	[[nodiscard]] Direction getDirection();
	void setDirection(Direction direction);

	void move();

};



#endif //TT2D_EX3_SNAKE_H