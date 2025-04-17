//
// Created by Tomáš Tatyrek on 17.04.2025.
//

#ifndef TT2D_RENDERER_H
#define TT2D_RENDERER_H

#include "Color.h"
#include "SDL3/SDL.h"
#include "TT2D/render/Renderable.h"

namespace TT2D {

	class Renderer {

	SDL_Renderer* mSdlRenderer;

public:
	Renderer() = delete;
	explicit Renderer(SDL_Window* sdlWindow);

	void render(const Renderable* renderable) const;
	void clear(Color color) const;
	void clear() const;
	void present() const;

};

} // TT2D

#endif //TT2D_RENDERER_H
