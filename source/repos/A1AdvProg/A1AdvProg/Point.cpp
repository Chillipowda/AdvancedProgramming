#include "Point.h"

Point::Point(){}
Point::Point(int x, int y){
	//set values passed in into scope so are not lost.
	this->x = x;
	this->y = y;
}
Point::~Point(){}
