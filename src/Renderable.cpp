//
// Created by Tomáš Tatyrek on 15/03/2025.
//

#include <algorithm>
#include "TT2D/Renderable.h"

void TT2D::Renderable::renderChildren() {

	if (hasRenderableChildren()) {

		for (Renderable* i : renderableChildren) {

			i->render();

		}

	}

}

void TT2D::Renderable::render() {
	renderChildren();
}

void TT2D::Renderable::add(Renderable *renderable) {

	if (renderable != this && !contains(renderable)) {

		renderableChildren.push_back(renderable);

	}

}

bool TT2D::Renderable::hasRenderableChildren() {
	return !renderableChildren.empty();
}

bool TT2D::Renderable::contains(Renderable *renderable) {
	return (std::find(renderableChildren.begin(), renderableChildren.end(), renderable) != renderableChildren.end());
}

void TT2D::Renderable::remove(Renderable *renderable) {

	renderableChildren.remove(renderable);

}
