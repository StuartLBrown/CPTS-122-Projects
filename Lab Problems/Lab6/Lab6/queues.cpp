#include "queues.h"
Queue::Queue(string data) {	
	this->head = new Node(data);
	this->tail = this->head;
}
Queue::Queue(const Queue &queue){
	(*this) = queue;
}
Queue::~Queue(void) {
	while (!isEmpty())
		dequeue();
}
bool Queue::isEmpty(void) {
	return this->head == nullptr;
}
bool Queue::enqueue(string data) {
	Node *temp = new Node(data);
	if (temp != nullptr) {
		if (isEmpty())
			this->head = this->tail = temp;
		else {
			this->tail->setNext(temp);
			this->tail = temp;
		}
		return true;
	}
	return false;
}
string Queue::dequeue(void) {
	if (isEmpty())
		return "";
	string val = "";
	Node *temp = nullptr;
	if (this->head == this->tail) {
		val = this->head->getData();
		temp = this->head;
		this->head = this->tail = nullptr;
		delete temp;
	}
	else {
		val = this->head->getData();
		temp = this->head;
		this->head = this->head->getNext();
		delete temp;
	}
	return val;
}
Node *Queue::getHead(void) {
	return this->head;
}
Node *Queue::getTail(void) {
	return this->tail;
}
void Queue::setHead(Node *n) {
	this->head = n;
}
void Queue::setTail(Node *n) {
	this->tail = n;
}
void Queue::printQueueRecursive(Queue q) {

}