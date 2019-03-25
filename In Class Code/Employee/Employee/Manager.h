#pragma once

#include <iostream>
#include <string>

#include "Employee.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Manager is a derived class, it's derived from Employee - need to complete the inheritance in class
class Manager : public Employee
{
public:
	Manager(const string &newName = "", const double &newPayRate = 0.0, const double &newHours = 0, const bool &newSalariedEmployee = false) {
		Employee(newName, newPayRate, newHours);
		this->isSalaried = newSalariedEmployee;
	}
	~Manager();

	// With inheritance, we should NOT have to redefine
	// many of the functions that we find in the Employee
	// class!
	bool getSalaried() {
		return this->isSalaried;
	}
	void setSalaried(bool newSalaried) {
		this->isSalaried = newSalaried;
	}
	double calculatePay() {
		if (isSalaried)
			return Manager::getPayRate();
		else
			return Employee::calculatePay();
	}

private:
	bool isSalaried;
};