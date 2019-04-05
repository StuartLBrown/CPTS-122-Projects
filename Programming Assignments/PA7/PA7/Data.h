#pragma once
#include "Stack.h"
class Data {
private:
	Stack s;
	int rNumber, ID, nAbsences;
public:
	string name, email, units, major, level;
	Data(int rNumber=0, int ID=0, string name="", string email="", string units="", string major="", string level="",int nAbsences = 0 );
	Data(const Data &d);

	int getRNumber() { return rNumber; }
	int getID() { return ID; }
	int getNAbsences() { return nAbsences; }
	void setNAbsences(int _nAbsences) {
		if (_nAbsences < 0)
			nAbsences = 0;
		else
			nAbsences = _nAbsences;
	}
	string peekStack() { return s.peek(); }

	Stack getStack() { return s; }

	void addAbscence(string &date) {
		s.push(date);
	}
	//pops the top absent date on the stack and returns that date
	string removeAbsence() {
		if (s.isEmpty())
			return "";
		return s.pop();
	}
};

Data::Data(int _rNumber, int _ID, string _name, string _email, string _units, string _major, string _level, int _nAbsences) {
	rNumber = _rNumber;
	ID = _ID;
	nAbsences = _nAbsences;
	name = _name;
	email = _email;
	units = _units;
	major = _major;
	level = _level;
}

Data::Data(const Data &d) {
	s = d.s;
	rNumber = d.rNumber;
	ID = d.ID;
	nAbsences = d.nAbsences;
	name = d.name;
	email = d.email;
	units = d.units;
	major = d.major;
	level = d.level;
}