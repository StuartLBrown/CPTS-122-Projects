#pragma once
#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::ostream;
class ExcercisePlan {
public:
	ExcercisePlan(int steps = 0, string = "", string date = "");
	ExcercisePlan(const ExcercisePlan &plan);
	void setSteps(int steos);
	void setName(string name_);
	void setDate(string date_);
	int getSteps(void) const;
	string getName(void) const;
	string getDate(void) const;
	void editGoal(void);
private:
	int goal_steps;
	string name, date;
};
ostream &operator<<(ostream &lhs, const ExcercisePlan &rhs);
ifstream &operator>>(ifstream &lhs, ExcercisePlan &rhs);
ofstream &operator<<(ofstream &lhs, const ExcercisePlan &rhs);