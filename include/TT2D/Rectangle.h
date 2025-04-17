//
// Created by tomta on 17.04.2025.
//

#ifndef TT2D_RECTANGLE_H
#define TT2D_RECTANGLE_H

#include "SDL3/SDL.h"

#include "Color.h"
#include "Renderable.h"

namespace TT2D {

class Rectangle : public Renderable {

	SDL_FRect mSdlRectangle;
	Color mColor;

public:

	Rectangle(float xPos, float yPos, float width, float height, Color color);

	void render(SDL_Renderer* sdlRenderer) const override;

};

} // TT2D

#endif //TT2D_RECTANGLE_H
