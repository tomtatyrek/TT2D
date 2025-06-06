#include "TT2D/TT2D.h"

int main() {

    using namespace TT2D;

	hello();

	Rectangle rect1 {50, 50, 300, 100, {0, 0, 255, 255}};
	FillRectangle rect2 {50, 350, 400, 100, {255, 0, 0, 255}};
	Line line1 {50, 50, 350, 150, {255, 255, 0, 255}};
	Point point1 {250, 400, {255, 255, 255, 255}};

	WindowProperties properties {};
	Window window {properties};
	window.add(&rect1);
	window.add(&rect2);
	window.add(&line1);
	window.add(&point1);

	App app {};
	app.add(&window);
	app.start();
}
