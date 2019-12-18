#include "Circle.h"
#include<string>
#include <iostream>
#include <vector>
Circle::Circle(int x, int y, int radius) : Shape(x,y) {
	//set radius in scope so that the value is not lost outside of these {} and can be used in calculateArea etc.
	this->radius = radius;
	calculateArea();
	calculatePerimeter();
	calculatePoints();
}
void Circle::calculatePoints() {
	//ensure points vector is clear before access so that points[0] is available
	points.clear();
	points.push_back(Point(leftTop.x, leftTop.y));
	points.push_back(Point(leftTop.x+(2 * radius), leftTop.y + (2 * radius)));
}
void Circle::calculatePerimeter(){
	//perimeter is pi*diameter aka pi*2r
	perimeter = pi * (2 * radius);
}
void Circle::calculateArea() {
	//area is pi * r^2
	area = pi*(radius*radius);
}
std::string Circle::toString() {
	//return the information about the shape for the user to view at leisure
	return
		"Circle[r="+std::to_string(radius)+"]\n"
		"Points[(" + std::to_string(points[0].x)+","+std::to_string(points[0].y)+") ("+std::to_string(points[1].x)+","+std::to_string(points[1].y)+")]\n"+
		"Area ="+std::to_string(area)+", Perimeter ="+std::to_string(perimeter);
}
void Circle::move(int newX, int newY) {
	//give lefttop new x and y values, recall the calculations to update
	leftTop = Point(newX, newY);
	calculatePoints();
}
void Circle::scale(float scaleX, float scaleY) {
	//multiple the radius by users scale value, ignore Y as scaling is isotropic
	std::cout << "Please note, the item you are scaling is scaled isotropically. Your Y scale does not affect this operation.\n";
	radius *= scaleX;
	calculateArea();
	calculatePerimeter();
	calculatePoints();
	//call toString to show user the update information
	std::cout << toString();
}
Circle::~Circle()
{
	std::cout << "Circle Deleted!\n";
}
