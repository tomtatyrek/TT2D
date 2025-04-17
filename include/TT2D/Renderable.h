//
// Created by Tomáš Tatyrek on 17.04.2025.
//

#ifndef TT2D_RENDERABLE_H
#define TT2D_RENDERABLE_H

namespace TT2D {

class Renderable {

public:

	virtual void render(SDL_Renderer* sdlRenderer) const = 0;

};

} // TT2D

#endif //TT2D_RENDERABLE_H
