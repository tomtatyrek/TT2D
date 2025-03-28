//
// Created by Tomáš Tatyrek on 15/03/2025.
//

#include "TT2D/App.h"
#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include "SDL3_ttf/SDL_ttf.h"

namespace TT2D {

	App::App() {

		// Initialize all necessary subsystems
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
		TTF_Init();

	}

	App::~App() {

		SDL_Quit();
		TTF_Quit();

	}

} // TT2D