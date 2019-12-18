#pragma once
#include "Shape.h"
#include "Movable.h"
#include <string>
class Square : public Shape, public Movable {
private:
	//these will only ever be used in the respective shapes constructor, therefore never needed public
	void Shape::calculatePoints();
	void Shape::calculateArea();
	void Shape::calculatePerimeter();
	int edge;
public:
	//these are used in the main(), thus need to be public for access
	Square(int x, int y, int e);
	std::string Shape::toString();
	void move(int newX, int newY) override;
	void scale(float scaleX, float scaleY) override;
	~Square();
};

