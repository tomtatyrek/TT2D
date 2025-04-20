#include <iostream>

#include "TT2D/TT2D.h"
#define PI 3.14159265359

int main() {

    using namespace TT2D;

	hello();

	Rectangle rect1 {50, 50, 300, 100, {0, 0, 255, 255}};
	FillRectangle rect2 {50, 350, 400, 100, {255, 0, 0, 255}};
	Line line1 {50, 50, 350, 150, {255, 255, 0, 255}};
	ColoredPoint point1 {250, 400, {255, 255, 255, 255}};
	ColoredPoint point2 {400, 300, {255, 255, 255, 255}};
	Arc arc1 {400, 300, 200, 200, 0, PI*3/2, {{255, 255, 255, 255}}};
	Arc arc2 {400, 300, 200, 300, 0, PI*3/2, {{255, 255, 0, 255}}};
	Point point3 {15,19};
	std::cout << point3.x << "  " << point3.y;

	WindowProperties properties {};
	Window window {properties};
	window.add(&rect1);
	window.add(&rect2);
	window.add(&line1);
	window.add(&point1);
	window.add(&point2);
	window.add(&arc1);
	window.add(&arc2);

	App app {};
	app.add(&window);
	app.start();
}
