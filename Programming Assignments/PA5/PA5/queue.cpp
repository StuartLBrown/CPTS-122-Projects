#include "queue.h"
Queue::Queue(const Queue &copy) {
	*this = copy;
}

Queue::Queue(Node *start) {
	head = tail = start;
}

Queue::~Queue() {
	//making the list empty and freeing up the memory
	while (!isEmpty())
		dequeue();
}

bool Queue::enqueue(const Data &d) {
	//initializing a new node - note d should already be put onto the heap
	Node *temp = new Node(&d);
	if (temp != nullptr) {
		//empty list
		if (isEmpty()) {
			head = tail = temp;
			return true;
		}
		//regular case
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
		//getting the data before it is freed
		Data d = head->getData();
		Node *temp = nullptr;
		//1 node case
		if (head == tail) {
			temp = head;
			head = tail = nullptr;
			delete temp;
		}
		//regular case
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
	if (rhs.isEmpty())
		return lhs;
	Node *cur = rhs.getHead();
	//running through the queue until the end of the queue is reached and printing out the data at each step
	while (cur != nullptr) {
		lhs << *cur->getData() << std::endl;
		cur = cur->getNext();
	}
	return lhs;
}
void runSimulation(int minutes) {
	//total time is the time that the user entered for the sim to run, cNumber is the customer number, eLaneStart is the time for the first and subsequent customers to arrive, nLaneStart is the same as eLaneStart but for the normal lane
	int totalTime = 0, cNumber = 1, eLaneStart = rand() % 5 + 1, nLaneStart = rand() % 5 + 3;
	//initializing the queues
	Queue expressLane(nullptr),normalLane(nullptr);
	//getting user input + verifying (values have to be greater than 0)
	for (int i = 1; i <= minutes; i++) {
		cout << "Time elapsed: " << i << " mins\n";
		//resets the customer number every 24 hours (60*24)
		if (i % 1440 == 0)
			cNumber = 1;
		//adding new customers
		if (i == eLaneStart) {
			//generating a service time for that customer
			int eLaneTime = rand() % 5 + 1;
			//adding new customer to the queue
			Data temp(cNumber, eLaneTime, expressLane.getTotalTime() + eLaneTime);
			expressLane.enqueue(temp);
			cNumber++;
			//generating a new time for the next customer to arrive
			eLaneStart = rand() % 5 + i + 1;
			//printing that a customer arrived
			cout << *expressLane.getTail()->getData() << "\nArrived in the express lane\n\n";
		}
		if (i == nLaneStart) {
			//generating a service time for that customer
			int nLaneTime = rand() % 5 + 3;
			//adding new customer to the queue
			Data temp(cNumber, nLaneTime, normalLane.getTotalTime() + nLaneTime);
			normalLane.enqueue(temp);
			cNumber++;
			//generating a new time for the next customer to arrive
			nLaneStart = rand() % 5 + i + 3;
			//printing that a customer arrived
			cout << *normalLane.getTail()->getData() << "\nArrived in the normal lane\n\n";
		}
		//removing customers
		//checking the head of the queue to see if the total time is 0 (that customer is done)
		if (!expressLane.isEmpty()&&expressLane.getHead()->getData()->getTTime() == 0) {
			//removing the customer from the queue
			Data temp = expressLane.dequeue();
			//print that a customer left
			cout << temp << "\nLeft the express lane\n\n";
		}
		if (!normalLane.isEmpty() && normalLane.getHead()->getData()->getTTime() == 0) {
			Data temp = normalLane.dequeue();
			//print that a customer left
			cout << temp << "\nLeft the normal lane\n\n";
		}
		//printing the queue every 10 mins
		if (i % 10 == 0) {
			if (!expressLane.isEmpty())
				cout << "Express Lane Queue:\n" << expressLane << "\n\n";
			else
				cout << "Express lane is empty\n\n";
			if (!normalLane.isEmpty())
				cout << "Normal Lane Queue:\n" << normalLane << "\n\n";
			else
				cout << "Normal lane is empty\n\n";
		}
		//decreases the total time of each person in the queue by 1 - 1 minute has passed to allow for them to advance
		decrementTotalTime(expressLane);
		decrementTotalTime(normalLane);
		system("cls");
	}
	cout << "Express Lane Queue:\n" << expressLane << "\n\n";
	cout << "Normal Lane Queue:\n" << normalLane << "\n\n";
}

int Queue::getTotalTime() {
	if (isEmpty())
		return 0;
	else {
		//goes to the end of queue and returns the total time
		return tail->getData()->getTTime();
	}
}

//has to be passed by reference since we are making changes to the queue
void decrementTotalTime(Queue &q) {
	if (q.isEmpty())
		return;
	else {
		//advances through the queue until the end of the queue is reached and decrements the total time of each node by 1
		Node *curr = q.getHead();
		Data  *val = nullptr;
		while (curr != nullptr) {
			val = curr->getData();
			//decrementing the total time by 1 of each node
			val->setTTime(val->getTTime() - 1);
			curr = curr->getNext();
		}
	}
}