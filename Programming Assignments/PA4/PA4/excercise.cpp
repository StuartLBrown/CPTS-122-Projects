#include "excercise.h"
ExcercisePlan::ExcercisePlan(int steps, string name_, string date_) {
	if (steps >= 0)
		goal_steps = steps;
	else
		goal_steps = 0;
	name = name_;
	date = date_;
}
ExcercisePlan::ExcercisePlan(const ExcercisePlan &plan) {
	goal_steps = plan.goal_steps;
	name = plan.name;
	date = plan.date;
}
ExcercisePlan::~ExcercisePlan(void) {
	delete this;
}
void ExcercisePlan::setSteps(int steps) {
	if (steps < 0)
		goal_steps = 0;
	else
		goal_steps = steps;
}
void ExcercisePlan::setName(string name_) {
	name = name_;
}
void ExcercisePlan::setDate(string date_) {
	date = date_;
}
int ExcercisePlan::getSteps(void) {
	return goal_steps;
}
string ExcercisePlan::getName(void) {
	return name;
}
string ExcercisePlan::getDate(void) {
	return date;
}
void ExcercisePlan::editGoal(void) {
	int newGoal = 0;
	while (newGoal <= 0) {
		cout << "Enter a new number of steps: ";
		cin >> newGoal;
	}
	goal_steps = newGoal;
	cout << *this;
}
ostream &operator<<(ostream &lhs, const ExcercisePlan &rhs) {
	ExcercisePlan p = rhs;
	lhs << "Steps: " << p.getSteps() << " | Plan Name: " << p.getName() << " | Plan Date: " << p.getDate() << std::endl;
	return lhs;
}
ifstream &operator >> (ifstream &lhs, ExcercisePlan &rhs) {
	string temp = "";
	std::getline(lhs, temp);
	rhs.setName(temp);
	std::getline(lhs, temp);
	rhs.setSteps(std::stoi(temp));
	std::getline(lhs, temp);
	rhs.setDate(temp);
	std::getline(lhs, temp);
	return lhs;
}
ofstream &operator<<(ofstream &lhs, const ExcercisePlan &rhs) {
	ExcercisePlan temp = rhs;
	lhs << temp.getName() << "\n" << temp.getSteps() << "\n" << temp.getDate() << std::endl;
	return lhs;
}