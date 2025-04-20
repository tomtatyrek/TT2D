//
// Created by Tomáš Tatyrek on 20.04.2025.
//

#ifndef TT2D_POINTCOLLECTION_H
#define TT2D_POINTCOLLECTION_H

#include <vector>
#include "Point.h"

namespace TT2D {

class PointCollection : public std::vector<Point> {

public:
	void movePoints(Point direction);
	void flipAroundAPoint(Point inversionCenter);
	void rotate(Point center, TT2D_RAT angle);

};

} // TT2D

#endif //TT2D_POINTCOLLECTION_H
