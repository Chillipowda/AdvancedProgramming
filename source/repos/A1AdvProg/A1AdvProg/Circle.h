#pragma once
#include "Shape.h"
#include "Movable.h"
#include <string>
class Circle : public Shape, public Movable {
private:
	//only ever used inside of Circle, thus never needed public
	void Shape::calculatePoints();
	void Shape::calculateArea();
	void Shape::calculatePerimeter();
	int radius;
	const double pi = 3.14159265359;
public:
	//these are accessed outside of circle, in main(), so public required
	Circle(int x, int y, int radius);
	std::string Shape::toString();
	void move(int newX, int newY) override;
	void scale(float scaleX, float scaleY) override;
	~Circle();
};

