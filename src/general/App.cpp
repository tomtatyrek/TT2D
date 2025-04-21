//
// Created by Tomáš Tatyrek on 15/03/2025.
//

#include <algorithm>

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

	void App::start() const {

		bool isRunning = true;

		while (isRunning) {

			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
					case SDL_EVENT_QUIT:
						isRunning = false;
						break;
				}
			}

			for (Window* window : mWindows) {
				window->clear();
				window->renderContent();
			}

			SDL_Delay(1);

		}

	}
	
	void App::add(Window* window) {
		if (!contains(window)) {
			mWindows.push_back(window);
		}
	}
	
	void App::remove(Window* window) {
		mWindows.remove(window);
	}

	bool App::contains(Window* window) const {
		if (std::find(mWindows.begin(), mWindows.end(), window) != mWindows.end()) return true;
		else return false;
	}


} // TT2D