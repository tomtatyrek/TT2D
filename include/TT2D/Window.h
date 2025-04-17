//
// Created by Tomáš Tatyrek on 15/03/2025.
//

#ifndef TT2D_WINDOW_H
#define TT2D_WINDOW_H

#include <list>

#include "SDL3/SDL.h"

#include "Renderer.h"

namespace TT2D {

	struct WindowProperties {

		const char* title = "default window title";
		int width = 800, height = 600;

		bool fullscreen = false;
		bool occluded = false;
		bool hidden = false;
		bool borderless = false;
		bool resizable = false;
		bool minimized = false;
		bool maximized = false;
		bool mouseGrabbed = false;
		bool inputFocus = false;
		bool mouseFocus = false;
		bool external = false;
		bool modal = false;
		bool highPixelDensity = false;
		bool mouseCapture = false;
		bool mouseRelativeMode = false;
		bool alwaysOnTop = false;
		bool utility = false;
		bool tooltip = false;
		bool popupMenu = false;
		bool keyboardGrabbed = false;
		bool transparent = false;
		bool notFocusable = false;
	};

	class Window {

		SDL_Window* mSdlWindow;
		Renderer* mRenderer;
		WindowProperties* mProperties;
		std::list<Renderable*> mContent {};

	public:

		Window() = delete;
		explicit Window(WindowProperties& windowProperties);

		~Window();

		[[nodiscard]] SDL_Window *getSdlWindow() const;
		void renderContent() const;
		void clear(Color color) const;
		void clear() const;

		void add(Renderable* renderable);
		void remove(Renderable* renderable);
		bool contains(Renderable* renderable);
	};

} // TT2D

#endif //TT2D_WINDOW_H
