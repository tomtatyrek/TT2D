//
// Created by Tomáš Tatyrek on 15/03/2025.
//

#ifndef TT2D_APP_H
#define TT2D_APP_H

#include <vector>
#include "TT2D/render/Window.h"

namespace TT2D {

	class App {

		//Stores all the windows which belong to this app
		std::list<Window*> mWindows;

	public:
		App();
		~App();

		void start();
		
		void add(Window* window);
		void remove(Window* window);
		bool contains(Window* window) const;

	};

} // TT2D

#endif //TT2D_APP_H
