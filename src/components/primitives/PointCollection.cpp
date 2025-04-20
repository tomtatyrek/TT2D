//
// Created by Tomáš Tatyrek on 20.04.2025.
//

#include "TT2D/components/primitives/PointCollection.h"

namespace TT2D {

	void PointCollection::movePoints(const Point direction) {
		for (Point point : this) {
			point.move(direction);
		}
	}

	void PointCollection::flipAroundAPoint(const Point inversionCenter) {
		for (Point point : this) {
			point.flipAroundAPoint(inversionCenter);
		}
	}

	void PointCollection::rotate(const Point center, const double angle) {
		for (Point point : this) {
			point.rotate(center, angle);
		}
	}

} // TT2D