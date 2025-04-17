//
// Created by Tomáš Tatyrek on 17.04.2025.
//

#ifndef TT2D_POINT_H
#define TT2D_POINT_H
#include "TT2D/render/Color.h"
#include "TT2D/render/Renderable.h"

namespace TT2D {

class Point : public Renderable {

	float mX, mY;
	Color mColor;

public:

	Point() = delete;
	Point(float x, float y, Color color);

	void render(SDL_Renderer *sdlRenderer) const override;

};

} // TT2D

#endif //TT2D_POINT_H
