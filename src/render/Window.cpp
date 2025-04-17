//
// Created by Tomáš Tatyrek on 15/03/2025.
//

#include "TT2D/render/Window.h"

#include <algorithm>

namespace TT2D {

	Window::Window(WindowProperties& windowProperties) : mProperties(&windowProperties) {

		const SDL_WindowFlags flags = SDL_WINDOW_HIDDEN
				| ((mProperties->fullscreen)         ? SDL_WINDOW_FULLSCREEN             : 0)
				| ((mProperties->occluded)           ? SDL_WINDOW_OCCLUDED               : 0)
				| ((mProperties->borderless)         ? SDL_WINDOW_BORDERLESS             : 0)
				| ((mProperties->resizable)          ? SDL_WINDOW_RESIZABLE              : 0)
				| ((mProperties->minimized)          ? SDL_WINDOW_MINIMIZED              : 0)
				| ((mProperties->mouseGrabbed)       ? SDL_WINDOW_MOUSE_GRABBED          : 0)
				| ((mProperties->inputFocus)         ? SDL_WINDOW_INPUT_FOCUS            : 0)
				| ((mProperties->mouseFocus)         ? SDL_WINDOW_MOUSE_FOCUS            : 0)
				| ((mProperties->external)           ? SDL_WINDOW_EXTERNAL               : 0)
				| ((mProperties->modal)              ? SDL_WINDOW_MODAL                  : 0)
				| ((mProperties->highPixelDensity)   ? SDL_WINDOW_HIGH_PIXEL_DENSITY     : 0)
				| ((mProperties->mouseCapture)       ? SDL_WINDOW_MOUSE_CAPTURE          : 0)
				| ((mProperties->mouseRelativeMode)  ? SDL_WINDOW_MOUSE_RELATIVE_MODE    : 0)
				| ((mProperties->alwaysOnTop)        ? SDL_WINDOW_ALWAYS_ON_TOP          : 0)
				| ((mProperties->utility)            ? SDL_WINDOW_UTILITY                : 0)
				| ((mProperties->tooltip)            ? SDL_WINDOW_TOOLTIP                : 0)
				| ((mProperties->popupMenu)          ? SDL_WINDOW_POPUP_MENU             : 0)
				| ((mProperties->keyboardGrabbed)    ? SDL_WINDOW_KEYBOARD_GRABBED       : 0)
				| ((mProperties->transparent)        ? SDL_WINDOW_TRANSPARENT            : 0)
				| ((mProperties->notFocusable)       ? SDL_WINDOW_NOT_FOCUSABLE          : 0);

		mSdlWindow = SDL_CreateWindow(
				mProperties->title,
				mProperties->width,
				mProperties->height,
				flags);

		mRenderer = new Renderer(mSdlWindow);

		if (!mProperties->hidden) SDL_ShowWindow(mSdlWindow);

	}

	Window::~Window() {

		SDL_DestroyWindow(mSdlWindow);
		delete mRenderer;

	}

	[[nodiscard]] SDL_Window* Window::getSdlWindow() const {
		return mSdlWindow;
	}

	void Window::renderContent() const {
		for (Renderable* renderable : mContent) {
			mRenderer->render(renderable);
		}
		mRenderer->present();
	}

	void Window::add(Renderable* renderable) {
		if (!contains(renderable)) {
			mContent.push_back(renderable);
		}
	}

	void Window::remove(Renderable* renderable) {
		mContent.remove(renderable);
	}

	bool Window::contains(Renderable* renderable) const{
		if (std::find(mContent.begin(), mContent.end(), renderable) != mContent.end()) return true;
		else return false;
	}

	void Window::clear(Color color) const {
		mRenderer->clear(color);
	}

	void Window::clear() const {
		mRenderer->clear();
	}

} // TT2D