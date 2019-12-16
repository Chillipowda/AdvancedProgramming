#pragma once
#include <vector>
#include "Point.h"
#include <string>
class Shape {
public:
	Shape();
	Shape(int x, int y);
	virtual std::string toString()=0;
	virtual ~Shape();
protected:
	//member access modifier protected to allow derived classes access to these, but nothing else
	double area;
	bool isCircular;
	double perimeter;
	Point leftTop;
	//create vector of points to store the full set of each shape
	std::vector<Point> points;
	//pure virtual functions to be overriden in each seperate shape class
	virtual void calculatePoints() = 0;
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
};

