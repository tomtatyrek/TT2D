//
// Created by Tomáš Tatyrek on 20.04.2025.
//

#ifndef TT2D_POINT_H
#define TT2D_POINT_H
#include "SDL3/SDL_rect.h"
#include "TT2D/TT2D_defines.h"

namespace TT2D {

class Point {

public:
	TT2D_RCT x = 0, y = 0;

	Point() = default;
	~Point() = default;
	Point(TT2D_RCT x, TT2D_RCT y);
	explicit Point(SDL_FPoint point);
	explicit Point(SDL_Point point);

	explicit operator SDL_FPoint() const;
	explicit operator SDL_Point() const;

	Point operator+ (Point point) const;
	Point operator- (Point point) const;
	void operator+= (Point point);
	void operator-= (Point point);

	Point operator+ (TT2D_RCT addend) const;
	Point operator- (TT2D_RCT subtrahend) const;
	Point operator* (TT2D_RCT multiplier) const;
	Point operator/ (TT2D_RCT divisor) const;

	//Dot product
	TT2D_RCT operator* (Point point) const;
	[[nodiscard]] TT2D_RCT dotProduct(Point point) const;

	void move(Point direction);
	void flipAroundAPoint(Point inversionCenter);
	[[nodiscard]] Point getPointReflection(Point inversionCenter) const;
	void rotate(Point center, TT2D_RAT angle);
	[[nodiscard]] Point getRotatedPoint(Point center, TT2D_RAT angle) const;

};

} // TT2D

#endif //TT2D_POINT_H
