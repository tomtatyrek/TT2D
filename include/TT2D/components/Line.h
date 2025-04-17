//
// Created by Tomáš Tatyrek on 17.04.2025.
//

#ifndef TT2D_LINE_H
#define TT2D_LINE_H

#include "SDL3/SDL_render.h"
#include "TT2D/render/Color.h"
#include "TT2D/render/Renderable.h"

namespace TT2D {

class Line : public Renderable {

	float mX1, mY1, mX2, mY2;
	Color mColor;

public:

	Line() = delete;
	Line(float x1, float y1, float x2, float y2, Color color);
	void render(SDL_Renderer *sdlRenderer) const override;

};

} // TT2D

#endif //TT2D_LINE_H
