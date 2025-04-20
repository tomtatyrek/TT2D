//
// Created by Tomáš Tatyrek on 17.04.2025.
//

#include "../../include/TT2D/components/Line.h"

namespace TT2D {
	Line::Line(const float x1, const float y1, const float x2, const float y2, const Color color):
	mX1(x1), mY1(y1), mX2(x2), mY2(y2), mColor(color) {}

	void Line::render(SDL_Renderer *sdlRenderer) const {

		SDL_SetRenderDrawColor(sdlRenderer, mColor.r, mColor.g, mColor.b, mColor.a);
		SDL_RenderLine(sdlRenderer, mX1, mY1, mX2, mY2);
		
	}
} // TT2D