//
// Created by Tomáš Tatyrek on 15/03/2025.
//

#include "TT2D/App.h"
#include "SDL3/SDL.h"
#include "SDL3_ttf/SDL_ttf.h"
#include "TT2D/TT2D_defines.h"

namespace TT2D {

	App::App() {

		// Initialize all necessary subsystems
		SDL_Init(TT2D_SDL_SUBSYSTEMS);
		TTF_Init();

	}

	App::~App() {

		SDL_Quit();
		TTF_Quit();

	}

} // TT2D