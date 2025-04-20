//
// Created by Tomáš Tatyrek on 19.04.2025.
//

#include "TT2D/components/Arc.h"

#include <cmath>

namespace TT2D {

	Arc::Arc(const float centerX, const float centerY, const float xSemiAxis, const float ySemiAxis, const float startAngle,
			 const float endAngle, const Color color)
		: mCenterX(centerX),
		  mCenterY(centerY),
		  mXSemiAxis(xSemiAxis),
		  mYSemiAxis(ySemiAxis),
		  mStartAngle(startAngle),
		  mEndAngle(endAngle),
		  mColor(color) {
	}

	void Arc::render(SDL_Renderer* sdlRenderer) const {

		//Calculate all the points of the arc:
		const int precision = static_cast<int>(std::ceil((mXSemiAxis + mYSemiAxis) * 2 * (mEndAngle - mStartAngle)));
		SDL_FPoint points [precision] = {};

		const float angleIncrement = (mEndAngle - mStartAngle) / precision;
		float angle = mStartAngle;

		if (mXSemiAxis == mYSemiAxis) {
			//The Arc lies on a circle
			for (int i = 0; i < precision; i++) {

				points[i].x = mXSemiAxis * std::cos(angle);
				points[i].y = mXSemiAxis * std::sin(angle);

				angle += angleIncrement;
			}
		} else if (mXSemiAxis > mYSemiAxis) {

			//TODO: Fix this

			//The major axis is parrallel to the x axis
			//const float excentricity = std::sqrt(std::pow(mXSemiAxis, 2) - std::pow(mYSemiAxis, 2));
			for (int i = 0; i < precision; i++) {
				const float distanceFromCenter = distanceFromCenerOfEllipse(mXSemiAxis, mYSemiAxis, angle);

				points[i].x = distanceFromCenter * std::cos(angle);
				points[i].y = distanceFromCenter * std::sin(angle);

				angle += angleIncrement;
			}
		} else {

			//TODO: Fix this

			//The major axis is parrallel to the y axis
			//const float excentricity = std::sqrt(std::pow(mYSemiAxis, 2) - std::pow(mXSemiAxis, 2));
			for (int i = 0; i < precision; i++) {
				const float distanceFromCenter = distanceFromCenerOfEllipse(mYSemiAxis, mXSemiAxis, angle);

				points[i].x = distanceFromCenter * std::cos(angle);
				points[i].y = distanceFromCenter * std::sin(angle);

				angle += angleIncrement;
			}
		}

		//Move the points regarding the center of the ellipse
		for (int i = 0; i < precision; i++) {
			points[i].x += mCenterX;
			points[i].y += mCenterY;
		}

		//Render the pointsd
		SDL_SetRenderDrawColor(sdlRenderer, mColor.r, mColor.g, mColor.b, mColor.a);
		SDL_RenderPoints(sdlRenderer, points, precision);


	}

	float Arc::distanceFromCenerOfEllipse(const float majorAxis, const float minorAxis, const float angle) {
		return majorAxis * minorAxis / std::sqrt(std::pow(majorAxis * std::cos(angle), 2) + std::pow(minorAxis * std::cos(angle), 2));
	}
} //TT2D