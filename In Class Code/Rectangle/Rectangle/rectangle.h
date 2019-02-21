#pragma once
#include <iostream>
#include <fstream>//fstream, ifstream, ofstream
class Rectangle {
public:
	//constructor
	//Rectangle(int length, int width);//constructor w/ parameters
	Rectangle(int length = 0, int width = 0);//default values - can only use in decleration

	//copy constructor
	Rectangle(Rectangle &r);//pass by reference - no copy of object is made

	//called implicitily
	~Rectangle();//destructor - free up resources, clean up streams

	//member functions - operations
	//getters - accessors
	int getLength();
	int getWidth();
	//setters - mutators
	void setLength(int length);
	void setWidth(int width);

	void printRectangle(void);
private : 
	//data members - attributes
	int length;
	int width;
};
void printRectangle(Rectangle r);

//overloading << (stream insertion operator to work w/ rectangle)
std::ostream &operator<<(std::ostream &lhs, Rectangle &rhs);