#pragma once
#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cout;
using std::cin;
using std::fstream;
using std::ostream;
class DietPlan {
public:
	DietPlan(int calories = 0, string name_= "", string date_ = "");
	DietPlan(const DietPlan &plan);
	void setCalories(int calories);
	void setName(string name_);
	void setDate(string date_);
	int getCalories(void);
	string getName(void);
	string getDate(void);
	void editGoal(void);
private:
	int goal_calories;
	string name, date;
};
ostream &operator<<(ostream &lhs, const DietPlan &rhs);
fstream &operator>>(fstream &lhs, DietPlan &rhs);
fstream &operator<<(fstream &lhs, const DietPlan &rhs);