#include "data.h"
class Node {
private:
	Data *data;
	Node *next;
public:
	Node(Node &copy);
	Node(const Data *data);
	Data *getData();
	Node *getNext();
	void setData(Data *d);
	void setNext(Node *n);
};