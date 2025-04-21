//
// Created by Tomáš Tatyrek on 20.04.2025.
//

#ifndef TT2D_POINTCOLLECTION_H
#define TT2D_POINTCOLLECTION_H

#include <array>
#include "Point.h"

namespace TT2D {

	template <std::size_t Size>
	class PointCollection : public std::array<Point, Size> {

	public:
		void movePoints(Point direction);
		void invertAroundPoint(Point inversionCenter);
		void rotate(Point center, TT2D_RAT angle);
		void forEach(void (*function)(Point& point));
		[[nodiscard]] Point getCenterPoint() const;
		void scale(float scale, Point centerPoint);
		void scale(float scale);

	};

} // TT2D

#endif //TT2D_POINTCOLLECTION_H
