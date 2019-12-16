#pragma once
class Movable {
public:
	Movable();
	//ensure move and scale exist for use in other classes
	virtual void move(int newX, int newY)=0;
	virtual void scale(float scaleX, float scaleY)=0;
	~Movable();
};

