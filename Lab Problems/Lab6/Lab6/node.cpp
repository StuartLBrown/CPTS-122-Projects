#include "node.h"
Node::Node(string newData, Node *n) {
	this->data = newData;
	this->next = n;
}
Node::~Node(void) {
	delete next;
}
Node *Node::getNext(void) {
	return this->next;
}
string Node::getData(void) {
	return this->data;
}
void Node::setData(string &_data) {
	this->data = _data;
}
void Node::setNext(Node *node) {
	this->next = node;
}