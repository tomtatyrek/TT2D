//
// Created by tomta on 17.04.2025.
//

#ifndef TT2D_RECTANGLE_H
#define TT2D_RECTANGLE_H

#include "SDL3/SDL.h"

#include "TT2D/render/Color.h"
#include "TT2D/render/Renderable.h"

namespace TT2D {

class Rectangle : public Renderable {

protected:

	SDL_FRect mSdlRectangle;
	Color mColor;

public:

	Rectangle(float xPos, float yPos, float width, float height, Color color);

	virtual void render(SDL_Renderer* sdlRenderer) const override;

};

} // TT2D

#endif //TT2D_RECTANGLE_H
