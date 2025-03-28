//
// Created by Tomáš Tatyrek on 15/03/2025.
//

#ifndef TT2D_RENDERABLE_H
#define TT2D_RENDERABLE_H

#include <list>
#include "SDL3/SDL.h"

namespace TT2D {

	class Renderable {

	protected:
		std::list<Renderable*> renderableChildren;
		SDL_Renderer* renderer;

	public:
		virtual void render();
		void renderChildren();
		void add(Renderable* renderable);
		void remove(Renderable* renderable);
		bool hasRenderableChildren();
		bool contains(Renderable* renderable);

		Renderable() = delete;

	};

}

#endif //TT2D_RENDERABLE_H
