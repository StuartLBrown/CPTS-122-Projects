#include "Node.h"
#pragma once
using std::cout;
using std::endl;
class TransactionNode : public Node {
private:
	int units;
public:
	//overloaded destructor
	~TransactionNode(){
		delete left, right;
	}
	//default constructor
	TransactionNode(string _data = "", int _units = 0) : Node(_data){
		units = _units;
	}

	//getter and setter
	int getUnits() { return units; }
	void setUnits(int newUnits) { units = newUnits; }

	//overloaded printData function
	void printData() {
		cout << data << " has " << units << " units" << endl;
	}
};