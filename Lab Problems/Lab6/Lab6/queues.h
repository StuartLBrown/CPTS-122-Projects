#include "node.h"
#pragma once
using std::ostream;
class Queue {
private:
	Node *head;
	Node *tail;
public:
	Queue(string data = "");
	Queue(const Queue &queue);
	~Queue(void);
	bool isEmpty(void);
	bool enqueue(string data);
	string dequeue(void);
	void printQueueRecursive(Queue q);
	Node *getHead(void);
	Node *getTail(void);
	void setHead(Node *n);
	void setTail(Node *n);
};