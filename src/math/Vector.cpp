//
// Created by Tomáš Tatyrek on 09/03/2025.
//

#include "Vector.h"
#include "defines.h"

#include <cmath>

TT2D::Vector::Vector() : x(0), y(0) {}
TT2D::Vector::Vector(TT2D_VNTYPE x, TT2D_VNTYPE y) : x(x), y(y) {}

TT2D_VNTYPE TT2D::Vector::size() const {
	return std::sqrt(std::pow(x, 2) + std::pow(y,2));
}

void TT2D::Vector::normalize() {
	auto size = this->size();
	x /= size;
	y /= size;
}
void TT2D::Vector::normalize(TT2D::Vector &vector) {
	vector.normalize();
}
