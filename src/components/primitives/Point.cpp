//
// Created by Tomáš Tatyrek on 20.04.2025.
//

#include <cmath>

#include "TT2D/components/primitives/Point.h"

namespace TT2D {
	Point::Point(const TT2D_RCT x, const TT2D_RCT y) : x(x), y(y) {}

	Point::Point(const SDL_FPoint point) {
		x = static_cast<TT2D_RCT>(point.x);
		y = static_cast<TT2D_RCT>(point.y);
	}

	Point::Point(const SDL_Point point) {
		x = static_cast<TT2D_RCT>(point.x);
		y = static_cast<TT2D_RCT>(point.y);
	}

	Point::operator SDL_FPoint() const {
		return {static_cast<float>(this->x), static_cast<float>(this->y)};
	}

	Point::operator SDL_Point() const {
		return {static_cast<int>(this->x), static_cast<int>(this->y)};
	}

	Point Point::operator+(const Point point) const {
		return {
			this->x + point.x,
			this->y + point.y
			};
	}

	Point Point::operator-(const Point point) const {
		return {
			this->x - point.x,
			this->y - point.y
			};
	}

	void Point::operator+=(const Point point) {
		*this = *this + point;
	}

	void Point::operator-=(const Point point) {
		*this = *this - point;
	}

	Point Point::operator+(const float addend) const {
		return {
			this->x + addend,
			this->y + addend
			};
	}

	Point Point::operator-(const float subtrahend) const {
		return {
			this->x - subtrahend,
			this->y - subtrahend
			};
	}

	Point Point::operator*(const float multiplier) const {
		return {
			this->x * multiplier,
			this->y * multiplier
			};
	}

	Point Point::operator/(const float divisor) const {
		return {
			this->x / divisor,
			this->y / divisor
			};
	}

	void Point::operator+=(const float addend) {
		*this = *this + addend;
	}

	void Point::operator-=(const float subtrahend) {
		*this = *this - subtrahend;
	}

	void Point::operator*=(const float multiplier) {
		*this = *this * multiplier;
	}

	void Point::operator/=(const float divisor) {
		*this = *this / divisor;
	}

	TT2D_RCT Point::operator*(const Point point) const {
		return this->x * point.x + this->y * point.y;
	}

	TT2D_RCT Point::dotProduct(const Point point) const {
		return this->x * point.x + this->y * point.y;
	}


	void Point::move(const Point direction) {
		x += direction.x;
		y += direction.y;
	}

	Point Point::getPointReflection(const Point inversionCenter) const {
		return {2*inversionCenter.x - x, 2*inversionCenter.y - y};
	}

	void Point::invertAroundPoint(const Point inversionCenter) {
		*this = getPointReflection(inversionCenter);
	}

	void Point::rotate(const Point center, const double angle) {
		*this = getRotatedPoint(center, angle);
	}

	Point Point::getRotatedPoint(const Point center, const double angle) const {
		if (angle == TT2D_PI) {
			return getPointReflection(center);
		}

		Point result = *this;
		result -= center;

		const TT2D_RAT sinTimesCos = std::sin(angle) * std::cos(angle);
		result.x *= static_cast<TT2D_RCT>(-sinTimesCos);
		result.y *= static_cast<TT2D_RCT>(sinTimesCos);

		result += center;
		return result;
	}

}// TT2D