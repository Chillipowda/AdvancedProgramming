#include "Square.h"
#include <iostream>

Square::Square(int x, int y, int e) : Shape(x,y)
{
	//set edge in scope so calculateArea etc. can use it in calculations then call calculations to build the shape
	this->edge = e;
	calculateArea();
	calculatePerimeter();
	calculatePoints();
}
void Square::calculateArea() {
	area = edge * edge;
}
void Square::calculatePerimeter() {
	perimeter = (4 * edge);
}
void Square::calculatePoints() {
	//clear points parameter for use each time.
	points.clear();
	//top left
	points.push_back(Point(leftTop.x, leftTop.y));
	//top right
	points.push_back(Point(leftTop.x+edge, leftTop.y));
	//bottom right
	points.push_back(Point(leftTop.x+edge, leftTop.y+edge));
	//bottom left
	points.push_back(Point(leftTop.x, leftTop.y+edge));
}
std::string Square::toString() {
	return
		//return data in format of sample execution
		"Square[e="+std::to_string(edge)+"]\n"+"Points[("+
		std::to_string(points[0].x) +","+ std::to_string(points[0].y) +") ("+ std::to_string(points[1].x) +","+ std::to_string(points[1].y)+ ") ("+
		std::to_string(points[2].x) +","+ std::to_string(points[2].y) +") ("+ std::to_string(points[3].x) +","+ std::to_string(points[3].y)+ ")]\n"+
		"Area="+std::to_string(area)+ ", Perimeter=" +std::to_string(perimeter);
}
void Square::move(int newX, int newY) {
	leftTop = Point(newX, newY);
	calculatePoints();
}
void Square::scale(float scaleX, float scaleY) {
	//multiply edge by users scale value
	edge *= scaleX;
	//inform user scale is isotropic and Y is irrelevant in this case.
	std::cout << "Please note, due to the shape you are trying to scale being a square, the scale is strictly isotropic, so your Y value has been disregarded\n";
	//recall calculations to update new shape
	calculateArea();
	calculatePerimeter();
	calculatePoints();
	//call toString at the end to show updated information
	std::cout << toString();
}
Square::~Square()
{
	std::cout << "Square deleted!\n";
}
