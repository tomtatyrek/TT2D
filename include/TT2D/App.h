//
// Created by Tomáš Tatyrek on 15/03/2025.
//

#ifndef TT2D_APP_H
#define TT2D_APP_H

#include "SDL3/SDL.h"
#include "Window.h"
#include <list>

namespace TT2D {

	class App {

		std::list<Window*> windows;

	public:
		App();
		~App();

	};

} // TT2D

#endif //TT2D_APP_H
