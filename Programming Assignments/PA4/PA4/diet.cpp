#include "diet.h"
DietPlan::DietPlan(int calories, string name_, string date_) {
	if (calories >= 0)
		goal_calories = calories;
	else
		goal_calories = 0;
	name = name_;
	date = date_;
}
DietPlan::DietPlan(const DietPlan &plan) {
	goal_calories = plan.goal_calories;
	name = plan.name;
	date = plan.date;
}
DietPlan::~DietPlan(void) {
	delete this;
}
void DietPlan::setCalories(int calories) {
	if (calories < 0)
		goal_calories = 0;
	else
		goal_calories = calories;
}
void DietPlan::setName(string name_) {
	name = name_;
}
void DietPlan::setDate(string date_) {
	date = date_;
}
int DietPlan::getCalories(void) {
	return goal_calories;
}
string DietPlan::getName(void) {
	return name;
}
string DietPlan::getDate(void) {
	return date;
}
void DietPlan::editGoal(void) {
	int newGoal = 0;
	while (newGoal <= 0) {
		cout << "Enter a new number of calories: ";
		cin >> newGoal;
	}
	goal_calories = newGoal;
	cout << *this;
}
ostream &operator<<(ostream &lhs, const DietPlan &rhs) {
	DietPlan p = rhs;
	lhs << "Calories: " << p.getCalories() << " | Plan Name: " << p.getName() << " | Plan Date: " << p.getDate() << std::endl;
	return lhs;
}
ifstream &operator>>(ifstream &lhs, DietPlan &rhs) {
	string temp = "";
	std::getline(lhs, temp);
	rhs.setName(temp);
	std::getline(lhs, temp);
	rhs.setCalories(std::stoi(temp));
	std::getline(lhs, temp);
	rhs.setDate(temp);
	std::getline(lhs, temp);
	return lhs;
}
ofstream &operator<<(ofstream &lhs, const DietPlan &rhs) {
	DietPlan temp = rhs;
	lhs << temp.getName() << "\n" << temp.getCalories() << "\n" << temp.getDate() << std::endl;
	return lhs;
}