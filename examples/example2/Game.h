//
// Created by Tomáš Tatyrek on 17/03/2025.
//

#ifndef TT2D_GAME_H
#define TT2D_GAME_H

#include "SDL3/SDL.h"

struct WindowProperties {

	const char* name;
	int width, height;
	SDL_WindowFlags flags;

};

class Game {

	SDL_Window *window;
	SDL_Renderer *renderer;

public:
	Game() = delete;
	Game(const WindowProperties& windowProperties, SDL_InitFlags flags);
	~Game();

	void run() const;

private:
	static bool initSDL(SDL_InitFlags flags);
	static void quitSDL();

};


#endif //TT2D_GAME_H
