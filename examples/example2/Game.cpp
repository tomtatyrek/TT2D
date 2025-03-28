//
// Created by Tomáš Tatyrek on 17/03/2025.
//

#include "Game.h"
#include <iostream>

Game::Game(const WindowProperties& windowProperties, const SDL_InitFlags flags) {

	initSDL(flags);

	window = SDL_CreateWindow(windowProperties.name, windowProperties.width, windowProperties.height, windowProperties.flags | SDL_WINDOW_HIDDEN);

	renderer = SDL_CreateRenderer(window, nullptr);


}

Game::~Game() {
	quitSDL();
}

void Game::run() const {

	bool quit = false;
	SDL_ShowWindow(window);

	//Main loop:
	while (!quit) {

		SDL_Event event;
		while (SDL_PollEvent(&event)) {

			switch (event.type) {
				case SDL_EventType::SDL_EVENT_QUIT:
					quit = true;
					break;
				default:
					std::cerr << "Unhandled event: " << event.type << std::endl;
			}
		}
	}


}


bool Game::initSDL(const SDL_InitFlags flags) {

	if(!SDL_Init(flags)) {
		std::cerr << "Failed to initialize SDL using given flags:\n"
			<< SDL_GetError();
	}

	return true;
}

void Game::quitSDL() {
	SDL_Quit();
}