#include "node.h"
#include <iostream>
#include <time.h>
#pragma once
using std::ostream;
using std::fstream;
using std::cin;
using std::cout;
class Queue {
private:
	//member variables
	Node *head;
	Node *tail;
public:
	//member functions

	//copy constructor
	Queue(const Queue &copy);

	//default constructor
	Queue(Node *start = nullptr);

	//destructor
	~Queue();

	//function that takes the initialized data (has to be put onto the heap already) and puts it at the end of the list
	//precondition: d must not be = nullptr
	//return value: whether it was succesfull
	bool enqueue(const Data &d);

	//function that removes the node at the end of the queue
	//precondition: queue must not be empty (checks anyway in function)
	//return value: the data at the end of the queue
	Data dequeue(void);

	//function that checks if the queue is empty
	//return value: whether the queue is empty - true, or not - false
	bool isEmpty(void)const;

	//basic getter functions
	Node *getHead(void)const;
	Node *getTail(void)const;

	//function that sums up the total time of all the data inside the queue
	//precondition: queue must not be empty (returns 0 if it is)
	//return value: the total time in the queue
	int getTotalTime();
};

//overloaded stream insertion operator to print the entire queue
ostream &operator<<(ostream &lhs, const Queue &rhs);

//runs the entire simulation, self contained function
//parameter: minutes must be greater than 0
void runSimulation(int minutes);

//decrements all the total time in the queue by 1 (used to move customers along the line)
void decrementTotalTime(Queue &q);
