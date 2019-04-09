#include "Node.h"
#pragma once
using std::cout;
using std::endl;
class TransactionNode : public Node {
private:
	int units;
public:
	~TransactionNode(){
		delete left, right;
	}
	TransactionNode(string _data = "", int _units = 0) : Node(_data){
		units = _units;
	}
	int getUnits() { return units; }
	void setUnits(int newUnits) { units = newUnits; }
	void printData() {
		cout << data << " has " << units << " units" << endl;
	}
};