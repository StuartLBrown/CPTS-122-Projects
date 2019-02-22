#include "excercise.h"
#include "diet.h"
#pragma once
class FitnessAppWrapper {
private:
	ExcercisePlan ePlan[7];
	DietPlan dPlan[7];
	fstream fExcercise;
	fstream fDiet;
public:
	void displayMenu(void);
	void displayPlan(DietPlan _dPlan[7]);
	void displayPlan(ExcercisePlan _ePlan[7]);
	void storeDailyPlan(DietPlan &dietPlan);
	void storeDailyPlan(ExcercisePlan &excercisePlan);
	void storeWeeklyPlan(DietPlan _dPlan[7]);
	void storeWeeklyPlan(ExcercisePlan _ePlan[7]);
	void loadDailyPlan(DietPlan &dietPlan);
	void loadDailyPlan(ExcercisePlan &excercisePlan);
	void loadWeeklyPlan(DietPlan _dPlan[7]);
	void loadWeeklyPlan(ExcercisePlan _ePlan[7]);
	void runApp(void);
};