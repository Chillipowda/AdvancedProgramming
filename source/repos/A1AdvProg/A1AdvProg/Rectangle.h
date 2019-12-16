#pragma once
#include "Shape.h"
#include "Movable.h"
#include <string>
class Rectangle : public Shape, public Movable {
private:
	//only ever used inside of Rectangle, thus never needed public
	void Shape::calculatePoints();
	void Shape::calculateArea();
	void Shape::calculatePerimeter();
	int height; int width;
public:
	//these are accessed outside of rectangle, in main(), so public required
	Rectangle(int x, int y, int height, int width);
	std::string Shape::toString();
	void move(int newX, int newY) override;
	void scale(float scaleX, float scaleY) override;
	~Rectangle();
};

