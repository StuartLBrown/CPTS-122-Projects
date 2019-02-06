#pragma once
#include <iostream>
class Rectangle {
public:
	//member functions - operations
	//getters - accessors
	int getLength();
	int getWidth();
	//setters - mutators
	void setLength(int length);
	void setWidth(int width);
private : 
	//data members - attributes
	int length;
	int width;
};