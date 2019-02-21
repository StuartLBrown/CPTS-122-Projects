#include "node.h"
#pragma once
//first in first out data structure (FIFO) 
class Queue {
public:
	Queue();
	bool enqueue(string &data);
	string dequeue(void);
private:
	Node *head, *tail;
};