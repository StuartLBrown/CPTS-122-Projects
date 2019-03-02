#include "Node.h"
Node::Node(int *newData) {
	data = newData;
	right = left = nullptr;
}
Node *Node::getRight() {
	return right;
}
Node *Node::getLeft() {
	return left;
}
int Node::getData() {
	return *data;
}
void Node::setRight(Node *node) {
	this->right = node;
}
void Node::setLeft(Node *node) {
	this->left = node;
}
void Node::setData(int *newData) {
	this->data = new int(*newData);
}