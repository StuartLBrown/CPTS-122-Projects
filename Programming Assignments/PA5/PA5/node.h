#include "data.h"
#pragma once
class Node {
private:
	//member variables
	//data will be initialized onto the heap w/ default constructor
	Data *data;
	Node *next;
public:
	//standard copy constructor
	Node(Node *copy);

	//standard default constructor
	Node(const Data *data);

	//standard getters and setters
	Data *getData();
	Node *getNext();
	void setData(Data *d);
	void setNext(Node *n);
};