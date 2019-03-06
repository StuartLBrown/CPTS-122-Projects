#include "node.h"
Node::Node(Node *copy) {
	this->data = copy->data;
	this->next = copy->next;
}
Node::Node(const Data *data) {
	this->data = new Data(data);
	this->next = nullptr;
}
Data *Node::getData() {
	return this->data;
}
Node *Node::getNext() {
	return this->next;
}
void Node::setData(Data *d) {
	this->data = d;
}
void Node::setNext(Node *n) {
	this->next = n;
}