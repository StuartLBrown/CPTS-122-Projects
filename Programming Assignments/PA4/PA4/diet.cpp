#include "diet.h"
#include <string>
using std::fstream;
using std::ostream;
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
ostream &operator<<(ostream &lhs, const DietPlan &rhs) {
	DietPlan p = rhs;
	lhs << "Calories: " << p.getCalories() << " | Plan Name: " << p.getName().c_str() << " | Plan Date: " << p.getDate().c_str() << std::endl;
	return lhs;
}
fstream &operator>>(fstream &lhs, DietPlan &rhs) {
	string temp;
	fstream >> temp;
	return lhs;
}