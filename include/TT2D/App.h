//
// Created by Tomáš Tatyrek on 15/03/2025.
//

#ifndef TT2D_APP_H
#define TT2D_APP_H

#include <vector>
#include "Window.h"

namespace TT2D {

	class App {

		//Stores all the windows which belong to this app
		std::vector<Window*> windows;

	public:
		App();
		~App();

	};

} // TT2D

#endif //TT2D_APP_H
