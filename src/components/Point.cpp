//
// Created by Tomáš Tatyrek on 17.04.2025.
//

#include "TT2D/components/Point.h"

namespace TT2D {
	Point::Point(const float x, const float y, const Color color) : mX(x), mY(y), mColor(color) {}

	void Point::render(SDL_Renderer *sdlRenderer) const {

		SDL_SetRenderDrawColor(sdlRenderer, mColor.r, mColor.g, mColor.b, mColor.a);
		SDL_RenderPoint(sdlRenderer, mX, mY);

	}

} // TT2D