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
	//normal constructor
	DietPlan(int calories = 0, string name_= "", string date_ = "");

	//copy constructor
	DietPlan(const DietPlan &plan);

	//sets the calories to the new value - checks if calories<0
	void setCalories(int calories);

	//sets the name of the plan to the new value
	void setName(string name_);

	//sets the date of the plan to the new value
	void setDate(string date_);

	//all getter functions - note they are constant since they don't modify any existing values
	int getCalories(void) const;
	string getName(void) const;
	string getDate(void) const;

	//takes user input to set the new goal (calories)
	void editGoal(void);
private:
	//member variables
	int goal_calories;
	string name, date;
};
//overloaded operators - stream insertion for cout
ostream &operator<<(ostream &lhs, const DietPlan &rhs);

//stream extraction for file reading
fstream &operator>>(fstream &lhs, DietPlan &rhs);

//stream insertion for file writing
fstream &operator<<(fstream &lhs, const DietPlan &rhs);