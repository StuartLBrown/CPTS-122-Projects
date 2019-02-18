#pragma once
#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::ostream;
using std::ofstream;
class DietPlan {
public:
	DietPlan(int calories = 0, string name_= "", string date_ = "");
	DietPlan(const DietPlan &plan);
	~DietPlan(void);
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
ifstream &operator>>(ifstream &lhs, DietPlan &rhs);
ofstream &operator<<(ofstream &lhs, const DietPlan &rhs);