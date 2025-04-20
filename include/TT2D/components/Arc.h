//
// Created by Tomáš Tatyrek on 19.04.2025.
//

#ifndef TT2D_ARC_H
#define TT2D_ARC_H
#include "SDL3/SDL_render.h"
#include "TT2D/render/Color.h"
#include "TT2D/render/Renderable.h"

namespace TT2D {

	class Arc : public Renderable {

		float mCenterX, mCenterY, mXSemiAxis, mYSemiAxis, mStartAngle, mEndAngle;
		Color mColor;

	public:
		/**
		 * Represents an arc of an ellipse, that can be rendered using a TT2D::Renderer.
		 *
		 * @param centerX x coordinate of center of the ellipse from left to right
		 * @param centerY y coordinate of center of the ellipse from top to bottom
		 * @param xSemiAxis size of the semiaxis parallel to the x axis
		 * @param ySemiAxis size of the semiaxis parallel to the y axis
		 * @param startAngle starting angle of the arc from the center of the ellipse, measured clockwise from x axis
		 * @param endAngle ending angle of the arc from the center of the ellipse, measured clockwise from x axis
		 * @param color color of the arc
		 */
		Arc(float centerX, float centerY, float xSemiAxis, float ySemiAxis, float startAngle, float endAngle, Color color);

		void render(SDL_Renderer* sdlRenderer) const override;

	private:
		static float distanceFromCenerOfEllipse(float majorAxis, float minorAxis, float angle);
};

} // TT2D

#endif //TT2D_ARC_H
