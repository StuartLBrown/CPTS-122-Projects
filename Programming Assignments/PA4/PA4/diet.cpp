#include "diet.h"
DietPlan::DietPlan(int calories, string name_, string date_) {
	//verifies that the calories>0
	if (calories >= 0)
		goal_calories = calories;
	else
		goal_calories = 0;
	name = name_;
	date = date_;
}
DietPlan::DietPlan(const DietPlan &plan) {
	//copy constructor
	goal_calories = plan.getCalories();
	name = plan.getName();
	date = plan.getDate();
}
void DietPlan::setCalories(int calories) {
	//verifies that the calories is >0
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
	//user input verifier
	while (newGoal <= 0) {
		cout << "Enter a new number of calories: ";
		cin >> newGoal;
	}
	goal_calories = newGoal;
	//printing the new plan
	cout << *this;
}
ostream &operator<<(ostream &lhs, const DietPlan &rhs) {
	//printing the plan
	lhs << "Calories: " << rhs.getCalories() << " | Plan Name: " << rhs.getName() << " | Plan Date: " << rhs.getDate() << std::endl;
	return lhs;
}
fstream &operator >> (fstream &lhs, DietPlan &rhs) {
	string temp = "";
	//getting each line for putting it into the plan
	std::getline(lhs, temp);
	rhs.setName(temp);
	std::getline(lhs, temp);
	//converting the string into an int
	rhs.setCalories(std::stoi(temp));
	std::getline(lhs, temp);
	rhs.setDate(temp);
	std::getline(lhs, temp);
	return lhs;
}
fstream &operator<<(fstream &lhs, const DietPlan &rhs) {
	//writing to the file
	lhs << rhs.getName() << "\n" << rhs.getCalories() << "\n" << rhs.getDate() << "\n  " << std::endl;
	return lhs;
}