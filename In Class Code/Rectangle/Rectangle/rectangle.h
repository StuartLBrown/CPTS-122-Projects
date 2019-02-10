#pragma once
#include <iostream>
class Rectangle {
public:
	//constructor
	Rectangle();//default
	//Rectangle(int length, int width);//constructor w/ parameters
	Rectangle(int length = 0, int width = 0);//default values - can only use in decleration

	~Rectangle();//destructor - free up resources, clean up streams

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