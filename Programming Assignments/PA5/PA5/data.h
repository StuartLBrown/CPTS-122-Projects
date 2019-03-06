#include <iostream>
#pragma once
using std::ostream;
class Data {
private:
	//member variables
	int cNumber;//customer number
	int sTime;//service time
	int tTime;//total time
public:
	//member functions

	//standard copy constructor
	Data(const Data *copy);

	//standard default constructor
	Data(int _cNumber = 0, int _sTime = 0, int _tTime = 0);

	//standard getters and setters
	int getCNumber() const;
	int getSTime() const;
	int getTTime() const;
	void setCNumber(int num);
	void setSTime(int time);
	void setTTime(int time);
};

//overloaded stream insertion operator - prints the all the member variables
ostream &operator<<(ostream &lhs, const Data &rhs);
