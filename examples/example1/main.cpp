#include "TT2D/TT2D.h"

int main() {

    using namespace TT2D;

	hello();

	WindowProperties properties {};

	Window window {properties};

	Rectangle rect1 {50, 50, 300, 100, {0, 0, 255, 255}};

	window.add(&rect1);

	window.renderContent();
}