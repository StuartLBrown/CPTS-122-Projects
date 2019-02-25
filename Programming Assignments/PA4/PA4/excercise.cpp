#include "excercise.h"
//note all of these functions are functionally the same as diet.cpp just with different names
ExcercisePlan::ExcercisePlan(int steps, string name_, string date_) {
	if (steps >= 0)
		goal_steps = steps;
	else
		goal_steps = 0;
	name = name_;
	date = date_;
}
ExcercisePlan::ExcercisePlan(const ExcercisePlan &plan) {
	*this = plan;
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
int ExcercisePlan::getSteps(void) const{
	return goal_steps;
}
string ExcercisePlan::getName(void) const{
	return name;
}
string ExcercisePlan::getDate(void) const{
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
	lhs << "Steps: " << rhs.getSteps() << " | Plan Name: " << rhs.getName() << " | Plan Date: " << rhs.getDate() << std::endl;
	return lhs;
}
fstream &operator>>(fstream &lhs, ExcercisePlan &rhs) {
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
fstream &operator<<(fstream &lhs, const ExcercisePlan &rhs) {
	lhs << rhs.getName() << "\n" << rhs.getSteps() << "\n" << rhs.getDate() << "\n  "<<std::endl;
	return lhs;
}