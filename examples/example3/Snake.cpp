//
// Created by Tomáš Tatyrek on 29.03.2025.
//

#include "Snake.h"
#include <cmath>
#include <vector>

Snake::Snake(const int tempo,
	const Direction startingDirection,
	const std::vector<BlockCoords>& snakeLocation)
	: snakePosition{snakeLocation}, tempo{std::abs(tempo)}, snakeDirection{startingDirection} {}

BlockCoords Snake::getHead() const {
	return snakePosition[0];
}

std::vector<BlockCoords> Snake::getBody() const {
	return {snakePosition.begin() + 1, snakePosition.end()};
}

Direction Snake::getDirection() {
	return snakeDirection;
}

void Snake::setDirection(Direction direction) {
	snakeDirection = direction;
}

void Snake::move() {
}
