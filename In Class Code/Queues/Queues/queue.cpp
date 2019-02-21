#include "queue.h"
Queue::Queue() {
	this->tail = this->head = nullptr;
}
bool Queue::enqueue(string &newString) {
	Node *temp = new Node(newString);
	if (temp != nullptr) {
		if (this->head == nullptr)//empty queue
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
	string val = "";
	Node *temp = nullptr;
	if (tail == head) {
		val = this->head->getName();
		temp = this->head;
		this->head = this->tail = nullptr;
		delete temp;
	}
	else {
		val = this->head->getName();
		temp = this->head;
		this->head = this->head->getNext();
		delete temp;
	}
	return val;
}