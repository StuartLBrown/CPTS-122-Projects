#include "queue.h"
Queue::Queue(const Queue &copy) {
	*this = copy;
}

Queue &Queue::operator=(const Queue &rhs) {
	if (!rhs.isEmpty()) {
		head = new Node(*rhs.head);
		Node *cur = head;
		while (cur != nullptr) {
			if (cur->getNext() != nullptr)
				cur->setNext(nullptr);
			else
				cur->setNext(new Node(*cur->getNext()));
			cur = cur->getNext;
		}
	}
	return (*this);
}

bool Queue::enqueue(const Data &d) {
	Node *temp = new Node(&d);
	if (temp != nullptr) {
		if (isEmpty()) {
			head = tail = temp;
			return true;
		}
		else {
			tail->setNext(temp);
			tail = temp;
			return true;
		}
	}
	return false;
}
Data Queue::dequeue(void) {
	if (!isEmpty()) {
		Data d = head->getData();
		Node *temp = nullptr;
		if (head == tail) {
			temp = head;
			head = tail = nullptr;
			delete temp;
		}
		else {
			temp = head;
			head = head->getNext();
			delete temp;
		}
		return d;
	}
	return nullptr;
}

Node *Queue::getHead(void) const{
	return head;
}
Node *Queue::getTail(void) const{
	return tail;
}

bool Queue::isEmpty(void)const {
	if (this->head == nullptr&&this->tail == nullptr)
		return true;
	return false;
}
ostream &operator<<(ostream &lhs, const Queue &rhs) {
	Node *cur = rhs.getTail();
	while (cur != nullptr) {
		lhs<<""
	}
}
