//
// Created by Tomáš Tatyrek on 17.04.2025.
//

#include "TT2D/TT2D.h"
#include "TT2D/Renderer.h"


namespace TT2D {

	Renderer::Renderer(SDL_Window* sdlWindow) :
	mSdlRenderer(SDL_CreateRenderer(sdlWindow, nullptr)) {

	}

	void Renderer::render(const Renderable* renderable) const {
		renderable->render(mSdlRenderer);
	}

	void Renderer::clear(Color color) const {
		SDL_SetRenderDrawColor(mSdlRenderer, color.r, color.g, color.b, color.a);
		SDL_RenderClear(mSdlRenderer);
	}

	void Renderer::clear() const {
		clear(TT2D_DEFAULT_RENDERER_CLEAR_COLOR);
	}

	void Renderer::present() const {
		SDL_RenderPresent(mSdlRenderer);
	}

} // TT2D