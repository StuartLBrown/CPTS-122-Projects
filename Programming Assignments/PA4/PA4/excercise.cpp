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
int ExcercisePlan::editGoal(void) {
	int newGoal = 0;
	while (newGoal <= 0) {
		cout << "Enter a new number of steps: ";
		cin >> newGoal;
	}
	goal_steps = newGoal;
}
std::ostream &operator<<(std::ostream &lhs, const ExcercisePlan &rhs) {
	ExcercisePlan p = rhs;
	lhs << "Steps: " << p.getSteps() << " | Plan Name: " << p.getName().c_str() << " | Plan Date: " << p.getDate().c_str() << std::endl;
	return lhs;
}