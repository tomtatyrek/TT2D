//
// Created by Tomáš Tatyrek on 20.04.2025.
//

#include "TT2D/components/primitives/PointCollection.h"

namespace TT2D {

	template <std::size_t Size>
	void PointCollection<Size>::movePoints(const Point direction) {
		for (Point point : this) {
			point.move(direction);
		}
	}

	template <std::size_t Size>
	void PointCollection<Size>::invertAroundPoint(const Point inversionCenter) {
		for (Point point : this) {
			point.invertAroundPoint(inversionCenter);
		}
	}

	template <std::size_t Size>
	void PointCollection<Size>::rotate(const Point center, const double angle) {
		for (Point point : this) {
			point.rotate(center, angle);
		}
	}

	template<std::size_t Size>
	void PointCollection<Size>::forEach(void(*function)(Point &point)) {
		for (Point point : this) {
			function(point);
		}
	}

	template<std::size_t Size>
	Point PointCollection<Size>::getCenterPoint() const {
		TT2D_RCT xSum = 0, ySum = 0;
		for (const Point point : this) {
			xSum += point.x;
			ySum += point.y;
		}
		return {xSum/Size, ySum/Size};
	}

	template<std::size_t Size>
	void PointCollection<Size>::scale(const float scale, const Point centerPoint) {
		for (Point point : this) {
			Point vectorFromCenter = point - centerPoint;
			vectorFromCenter *= scale;
			point = centerPoint + vectorFromCenter;
		}
	}

	template<std::size_t Size>
	// ReSharper disable once CppMemberFunctionMayBeConst
	void PointCollection<Size>::scale(const float scale) {
		scale(scale, getCenterPoint());
	}
} // TT2D