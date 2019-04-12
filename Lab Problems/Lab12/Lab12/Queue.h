#include "Node.h"
#pragma once
#include <string>
#include "Packet.h"
using std::cin;
template<class T>
class Queue : private List<T> {
public:
	void enqueue(const T &newData);
	T dequeue();
	T getEndQueue() {
		if (!this->isEmpty())
			return ((List<T>*)this)->firstPtr->data;
	}
	void printFrontBack() {
		cout << ((List<T>*)this)->firstPtr->data<<std::endl;
		cout << ((List<T>*)this)->lastPtr->data<< std::endl;
	}
	friend void runApplication();
};


template<class T>
void Queue<T>::enqueue(const T &newData) {
	this->insertAtBack(newData);
}

template<class T>
T Queue<T>::dequeue() {
	T temp;
	this->removeFromFront(temp);
	return temp;
}

void runApplication() {
	Queue<Packet> qPackets;
	int time = 0;
	cout << "Enter a time (in seconds) to run the simulation for: ";
	cin >> time;
	int processingTime = (rand() % 10) + 1;
	for (int i = 0; i < time; i++) {
		int newPacket = rand() % 5;
		if (processingTime == 0) {
			qPackets.dequeue();
			processingTime = (rand() % 10) + 1;
		}
		if (newPacket == 0) {
			cout << "Enter a message for the new packet: ";
			string m;
			cin >> m;
			Packet nP(m.length(), m);
			qPackets.enqueue(nP);
		}
		qPackets.printFrontBack();
		processingTime--;
	}
}