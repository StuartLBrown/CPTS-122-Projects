#pragma once
#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cout;
using std::cin;
using std::fstream;
using std::ostream;
class ExcercisePlan {
public:
	//normal constructor
	ExcercisePlan(int steps = 0, string = "", string date = "");

	//copy constructor
	ExcercisePlan(const ExcercisePlan &plan);

	//sets the steps to the new value - checks if steps<0
	void setSteps(int steps);

	//sets the name of the plan to the new value
	void setName(string name_);

	//sets the date of the plan to the new value
	void setDate(string date_);

	//all getter functions - note they are constant since they don't modify any existing values
	int getSteps(void) const;
	string getName(void) const;
	string getDate(void) const;

	//takes user input to set the new goal (steps)
	void editGoal(void);
private:
	//member variables
	int goal_steps;
	string name, date;
};
//overloaded operators - stream insertion for cout
ostream &operator<<(ostream &lhs, const ExcercisePlan &rhs);

//stream extraction for file reading
fstream &operator>>(fstream &lhs, ExcercisePlan &rhs);

//stream insertion for file writing
fstream &operator<<(fstream &lhs, const ExcercisePlan &rhs);