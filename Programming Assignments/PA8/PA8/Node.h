#include <iostream>
#include <string>
using std::string;
class Node abstract{
protected:
	string data;
	Node *left;
	Node *right;
public:
	virtual ~Node();
	Node(string _data = "") {
		data = _data;
		left = nullptr;
		right = nullptr;
	}
	void setData(string newData) { data = newData; }
	void setLeft(Node *newLeft) { left = newLeft; }
	void setRight(Node *newRight) { right = newRight; }
	string getData() { return data; }
	Node *getLeft() { return left; }
	Node *getRight() { return right; }
	virtual void printData() = 0;
};