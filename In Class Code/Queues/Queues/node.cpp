#include "node.h"
Node::Node(const string &s) {
	name = s;
	//start using nullptr instead of NULL (better overall
	next = nullptr;
}
Node::Node(const Node &n) {

}
Node::~Node(void) {

}
Node *Node::getNext(void) const{
	return this->next;
}
string Node::getName(void) const {
	return this->name;
}
void Node::setName(string &newString) {
	this->name = newString;
}
void Node::setNext(Node *pNext) {
	this->next = pNext;
}