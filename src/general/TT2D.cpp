#include "TT2D/TT2D.h"
#include "SDL3/SDL.h"

#include <iostream>

void TT2D::hello() {

	SDL_LogMessage(SDL_LOG_CATEGORY_TEST, SDL_LOG_PRIORITY_INFO, "%s", "This is an SDL log message saying Hello World.\n");
	std::cout << "This is standard output saying Hello World\n";

}