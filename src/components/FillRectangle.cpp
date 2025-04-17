//
// Created by Tomáš Tatyrek on 17.04.2025.
//

#include "TT2D/components/FillRectangle.h"

namespace TT2D {

	void FillRectangle::render(SDL_Renderer* sdlRenderer) const {

		SDL_SetRenderDrawColor(sdlRenderer, mColor.r, mColor.g, mColor.b, mColor.a);
		SDL_RenderFillRect(sdlRenderer, &mSdlRectangle);

	}

	FillRectangle::FillRectangle(const float xPos, const float yPos, const float width, const float height, const Color color) :
			Rectangle(xPos, yPos, width, height, color) {}

}// namespace TT2D