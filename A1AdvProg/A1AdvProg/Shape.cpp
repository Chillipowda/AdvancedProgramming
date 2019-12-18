#include "Shape.h"
#include <string>
Shape::Shape(){}
Shape::Shape(int x, int y) : leftTop(x,y) {
	this->isCircular = isCircular;
}
void Shape::calculatePoints()
{
}
void Shape::calculateArea(){
}
void Shape::calculatePerimeter(){
}
std::string Shape::toString(){
	return std::string();
}
Shape::~Shape(){
}
