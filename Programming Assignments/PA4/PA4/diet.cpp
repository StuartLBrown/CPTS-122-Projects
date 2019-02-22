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
int DietPlan::getCalories(void) const{
	return goal_calories;
}
string DietPlan::getName(void) const{
	return name;
}
string DietPlan::getDate(void) const{
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
	lhs << "Calories: " << rhs.getCalories() << " | Plan Name: " << rhs.getName() << " | Plan Date: " << rhs.getDate() << std::endl;
	return lhs;
}
fstream &operator >> (fstream &lhs, DietPlan &rhs) {
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
fstream &operator<<(fstream &lhs, const DietPlan &rhs) {
	lhs << rhs.getName() << "\n" << rhs.getCalories() << "\n" << rhs.getDate() << "\n  "<<std::endl;
	return lhs;
}