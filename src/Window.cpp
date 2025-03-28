//
// Created by Tomáš Tatyrek on 15/03/2025.
//

#include "TT2D/Window.h"
#include <algorithm>

namespace TT2D {

	void Window::add(Renderable *renderable) {

		if (!contains(renderable)) {

			renderableContent.push_back(renderable);

		}

	}

	void Window::remove(Renderable *renderable) {
		renderableContent.remove(renderable);
	}

	bool Window::contains(Renderable *renderable) {
		return (std::find(renderableContent.begin(), renderableContent.end(), renderable) != renderableContent.end());
	}

	void Window::render() {

	}

	void Window::show() {
		SDL_ShowWindow(SDLWindow);
	}

	void Window::hide() {
		SDL_HideWindow(SDLWindow);
	}

	Window::Window(WindowProperties& windowProperties) : properties(&windowProperties) {

		SDL_WindowFlags flags = SDL_WINDOW_HIDDEN
				| ((properties->fullscreen)         ? SDL_WINDOW_FULLSCREEN             : 0)
				| ((properties->occluded)           ? SDL_WINDOW_OCCLUDED               : 0)
				| ((properties->borderless)         ? SDL_WINDOW_BORDERLESS             : 0)
				| ((properties->resizable)          ? SDL_WINDOW_RESIZABLE              : 0)
				| ((properties->minimized)          ? SDL_WINDOW_MINIMIZED              : 0)
				| ((properties->mouseGrabbed)       ? SDL_WINDOW_MOUSE_GRABBED          : 0)
				| ((properties->inputFocus)         ? SDL_WINDOW_INPUT_FOCUS            : 0)
				| ((properties->mouseFocus)         ? SDL_WINDOW_MOUSE_FOCUS            : 0)
				| ((properties->external)           ? SDL_WINDOW_EXTERNAL               : 0)
				| ((properties->modal)              ? SDL_WINDOW_MODAL                  : 0)
				| ((properties->highPixelDensity)   ? SDL_WINDOW_HIGH_PIXEL_DENSITY     : 0)
				| ((properties->mouseCapture)       ? SDL_WINDOW_MOUSE_CAPTURE          : 0)
				| ((properties->mouseRelativeMode)  ? SDL_WINDOW_MOUSE_RELATIVE_MODE    : 0)
				| ((properties->alwaysOnTop)        ? SDL_WINDOW_ALWAYS_ON_TOP          : 0)
				| ((properties->utility)            ? SDL_WINDOW_UTILITY                : 0)
				| ((properties->tooltip)            ? SDL_WINDOW_TOOLTIP                : 0)
				| ((properties->popupMenu)          ? SDL_WINDOW_POPUP_MENU             : 0)
				| ((properties->keyboardGrabbed)    ? SDL_WINDOW_KEYBOARD_GRABBED       : 0)
				| ((properties->transparent)        ? SDL_WINDOW_TRANSPARENT            : 0)
				| ((properties->notFocusable)       ? SDL_WINDOW_NOT_FOCUSABLE          : 0);

		SDLWindow = SDL_CreateWindow(
				properties->title,
				properties->width,
				properties->height,
				flags);

		renderer = SDL_CreateRenderer(SDLWindow, nullptr);

		if (!properties->hidden) SDL_ShowWindow(SDLWindow);

	}

	Window::~Window() {

		SDL_DestroyWindow(SDLWindow);
		SDL_DestroyRenderer(renderer);

	}

} // TT2D