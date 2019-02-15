#include <iostream>
class DietPlan {
public:
	DietPlan(int calories = 0, std::string = "", std::string date = "");
	DietPlan(const DietPlan &plan);
	~DietPlan(void);
private:
	int goal_calories;
	std::string name, date;
};
class ExcercisePlan {
public:
	ExcercisePlan(int steps = 0, std::string = "", std::string date = "");
	ExcercisePlan(const ExcercisePlan &plan);
	~ExcercisePlan(void);
private:
	int goal_steps;
	std::string name,date;
};
class FitnessAppWrapper {

};