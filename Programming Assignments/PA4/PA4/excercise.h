#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
class ExcercisePlan {
public:
	ExcercisePlan(int steps = 0, string = "", string date = "");
	ExcercisePlan(const ExcercisePlan &plan);
	~ExcercisePlan(void);
	void setSteps(int steos);
	void setName(string name_);
	void setDate(string date_);
	int getSteps(void);
	string getName(void);
	string getDate(void);
	int editGoal(void);
private:
	int goal_steps;
	string name, date;
};
std::ostream &operator<<(std::ostream &lhs, const ExcercisePlan &rhs);