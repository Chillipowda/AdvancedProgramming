#include "Rectangle.h"
#include <iostream>
#include <string>
Rectangle::Rectangle(int x, int y, int h, int w) : Shape(x,y) {
	//set values in scope of Rectangle so they can be used by calculateArea etc.
	this->height = h;
	this->width = w;
	calculateArea();
	calculatePerimeter();
	calculatePoints();
}
void Rectangle::calculateArea(){
	//typical area calculation
	area = height * width;
}
void Rectangle::calculatePerimeter(){
	//typical perimeter calculation
	perimeter = (2 * height) + (2 * width);
}
void Rectangle::calculatePoints(){
	points.clear();
	//left top
	points.push_back(Point(leftTop.x, leftTop.y));
	//right top
	points.push_back(Point(leftTop.x+width, leftTop.y));
	//right bottom
	points.push_back(Point(leftTop.x+width, leftTop.y+height));
	//left bottom
	points.push_back(Point(leftTop.x, leftTop.y+height));
}
std::string Rectangle::toString() {
	return
		//this return has been formatted to look like the sample execution
		"Rectangle[h="+std::to_string(height)+",w="+std::to_string(width)+"]\n"+
		"Points[("+std::to_string(points[0].x) + "," + std::to_string(points[0].y) + ") (" + std::to_string(points[1].x) + "," + std::to_string(points[1].y) + ") (" +
		std::to_string(points[2].x) + "," + std::to_string(points[2].y) + ") (" + std::to_string(points[3].x) + "," + std::to_string(points[3].y)+")]\n" + 
		"Area = " + std::to_string(area) + ", Perimeter = " + std::to_string(perimeter);
}
void Rectangle::move(int newX, int newY){
	//give leftTop the new x and y for the shape, then calculate all following points
	leftTop = Point(newX, newY);
	calculatePoints();
}
void Rectangle::scale(float scaleX, float scaleY) {
	//multiply by the scale factoral. Innately rounded down
	width *= scaleX;
	height *= scaleY;
	//recall all calculations then display updated information
	calculateArea();
	calculatePerimeter();
	calculatePoints();
	std::cout<<toString();
}
Rectangle::~Rectangle()
{
	//is called when shape is deleted in postprocessing
	std::cout << "Rectangle deleted!\n";
}
