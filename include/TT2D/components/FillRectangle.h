//
// Created by tomta on 17.04.2025.
//

#ifndef TT2D_FILLRECTANGLE_H
#define TT2D_FILLRECTANGLE_H

#include "Rectangle.h"

namespace TT2D {

	class FillRectangle : public Rectangle {

	public:

		FillRectangle() = delete;
		FillRectangle(float xPos, float yPos, float width, float height, Color color);

		void render(SDL_Renderer* sdlRenderer) const override;

	};

}// namespace TT2D

#endif//TT2D_FILLRECTANGLE_H
