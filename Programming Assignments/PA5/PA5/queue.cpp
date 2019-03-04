#include "queue.h"
Queue::Queue(const Queue &copy) {
	*this = copy;
}

Queue::Queue(Node *start) {
	head = tail = start;
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
		lhs << cur->getData();
		cur = cur->getNext();
	}
}
void runSimulation() {
	int totalTime = 0, cNumber = 1, eLaneStart = rand() % 5 + 1, nLaneStart = rand() % 5 + 3;
	Queue expressLane, normalLane;
	while (totalTime <= 0) {
		cout << "Enter an amount of minutes for the simulation to run: ";
		cin >> totalTime;
	}
	for (int i = 0; i < totalTime; i++) {
		if (i % 10 == 0) {
			cout << expressLane;
			cout << normalLane;
		}
		if (i % 1440 == 0)
			cNumber = 1;
		//adding new customers
		if (i == eLaneStart) {
			//customer arrived, add new customer to queue and generate a new random time for the next customer to arrive
			int eLaneTime = rand() % 5 + 1;
			expressLane.enqueue(*new Data(cNumber, eLaneTime, expressLane.getTotalTime()+eLaneTime));
			cNumber++;
			eLaneStart = rand() % 5 + i + 1;
		}
		if (i == nLaneStart) {
			//customer arrived, add new customer to queue and generate a new random time for the next customer to arrive
			int nLaneTime = rand() % 5 + 3;
			normalLane.enqueue(*new Data(cNumber, nLaneTime, normalLane.getTotalTime()+nLaneTime));
			cNumber++;
			nLaneStart = rand() % 5 + i + 3;
		}
		//removing customers
		if (expressLane.getHead()->getData()->getTTime() == 0) {
			Data temp = expressLane.dequeue();
			//print that a customer left
			cout << temp << " Left\n";
		}
		if (normalLane.getHead()->getData()->getTTime() == 0) {
			Data temp = normalLane.dequeue();
			//print that a customer left
			cout << temp << " Left\n";
		}

		decrementTotalTime(expressLane);
		decrementTotalTime(normalLane);
	}
}

int Queue::getTotalTime() {
	if (isEmpty())
		return 0;
	else {
		Node *curr = tail;
		int sum = 0;
		while (curr->getNext()!= nullptr) {
			curr = curr->getNext();
		}
		sum = curr->getData()->getTTime();
		return sum;
	}
}

void decrementTotalTime(Queue &q) {
	if (q.isEmpty())
		return;
	else {
		Node *curr = q.getHead();
		Data  *val = nullptr;
		while (curr != nullptr) {
			val = curr->getData();
			val->setTTime(val->getTTime() - 1);
			curr = curr->getNext();
		}
	}
}