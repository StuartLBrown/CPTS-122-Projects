#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
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
private:
	int goal_calories;
	string name, date;
};
std::ostream &operator<<(std::ostream &lhs, const DietPlan &rhs);
std::ifstream &operator>>(std::ifstream &lhs, const DietPlan &rhs);