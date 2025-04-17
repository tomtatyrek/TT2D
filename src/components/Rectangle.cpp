//
// Created by tomta on 17.04.2025.
//

#include "TT2D/components/Rectangle.h"

namespace TT2D {

	Rectangle::Rectangle(float xPos, float yPos, float width, float height, Color color) :
			mSdlRectangle({xPos, yPos, width, height}),
			mColor(color) {

	}

	void Rectangle::render(SDL_Renderer* sdlRenderer) const {

		SDL_SetRenderDrawColor(sdlRenderer, mColor.r, mColor.g, mColor.b, mColor.a);
		SDL_RenderRect(sdlRenderer, &mSdlRectangle);

	}

} // TT2D