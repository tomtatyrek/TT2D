#include "TT2D/TT2D.h"

int main() {

    using namespace TT2D;

	hello();

	Rectangle rect1 {50, 50, 300, 100, {0, 0, 255, 255}};

	WindowProperties properties {};
	Window window {properties};
	window.add(&rect1);

	App app {};
	app.add(&window);
	app.start();
}