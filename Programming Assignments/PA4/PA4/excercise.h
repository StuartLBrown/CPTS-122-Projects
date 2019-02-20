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
	ExcercisePlan(int steps = 0, string = "", string date = "");
	ExcercisePlan(const ExcercisePlan &plan);
	void setSteps(int steos);
	void setName(string name_);
	void setDate(string date_);
	int getSteps(void);
	string getName(void);
	string getDate(void);
	void editGoal(void);
private:
	int goal_steps;
	string name, date;
};
ostream &operator<<(ostream &lhs, const ExcercisePlan &rhs);
fstream &operator >> (fstream &lhs, ExcercisePlan &rhs);
fstream &operator<<(fstream &lhs, const ExcercisePlan &rhs);