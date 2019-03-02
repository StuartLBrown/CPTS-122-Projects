#include <iostream>
class Node {
public:
	Node(int *newData);
	Node *getRight();
	Node *getLeft();
	int getData();
	void setRight(Node *node);
	void setLeft(Node *node);
	void setData(int *newData);
private:
	int *data;
	Node *right, *left;
};