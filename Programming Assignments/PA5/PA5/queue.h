#include "data.h"
#include "node.h"
#include <iostream>
#include <time.h>
using std::ostream;
using std::fstream;
using std::cin;
using std::cout;
class Queue {
private:
	Node *head;
	Node *tail;
public:
	Queue(const Queue &copy);
	Queue(Node *start = nullptr);
	bool enqueue(const Data &d);
	Data dequeue(void);
	bool isEmpty(void)const;
	Queue &operator=(const Queue &lhs);
	Node *getHead(void)const;
	Node *getTail(void)const;
	int getTotalTime();
};
ostream &operator<<(ostream &lhs, const Queue &rhs);
void runSimulation();
void decrementTotalTime(Queue &q);
