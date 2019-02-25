#include "excercise.h"
#include "diet.h"
#pragma once
//class to hold functions for the main application
class FitnessAppWrapper {
private:
	//weekly plans
	ExcercisePlan ePlan[7];
	DietPlan dPlan[7];
	//fstreams for the 2 files
	fstream fExcercise;
	fstream fDiet;
public:
	//destructor
	~FitnessAppWrapper(void);

	//main constructor - used it to replace runApp (essentially a useless function)
	//parameters: dFile - name for the dietPlan file, eFile - name for the excercisePlan file 
	FitnessAppWrapper(string dFile = "diet.txt", string eFile = "excercise.txt");

	//displays the main menu for the application - also handles all user input
	void displayMenu(void);

	//displays the entire weekly plan using << overloaded operators 
	void displayPlan(DietPlan _dPlan[7]);

	//same thing as above except for the excercise plan
	void displayPlan(ExcercisePlan _ePlan[7]);

	//stores a single daily plan into the relevant file
	//dietPlan must actually have member variables filled in
	void storeDailyPlan(DietPlan &dietPlan);

	//same thing as above
	void storeDailyPlan(ExcercisePlan &excercisePlan);

	//stores the whole plan using storeDailyPlan(relevant object)
	void storeWeeklyPlan(DietPlan _dPlan[7]);

	//same thing as above
	void storeWeeklyPlan(ExcercisePlan _ePlan[7]);

	//loads a single daily plan fromt the relevant file into the referenced object
	void loadDailyPlan(DietPlan &dietPlan);

	//same thing as above
	void loadDailyPlan(ExcercisePlan &excercisePlan);

	//loads an entire weekly plan into the array - note the file must have at least 7 entries (any extra will be deleted)
	void loadWeeklyPlan(DietPlan _dPlan[7]);

	//same thing as above
	void loadWeeklyPlan(ExcercisePlan _ePlan[7]);
};