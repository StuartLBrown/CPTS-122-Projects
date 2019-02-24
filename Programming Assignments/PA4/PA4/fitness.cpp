#include "fitness.h"
FitnessAppWrapper::~FitnessAppWrapper(void) {
	fExcercise.close();
	fDiet.close();
}
FitnessAppWrapper::FitnessAppWrapper(string dFile, string eFile) {
	fDiet.open(dFile, fstream::in);
	fExcercise.open(eFile, fstream::in);
	displayMenu();
}
void FitnessAppWrapper::displayMenu(void) {
	int input = 1;
	while (input > 0 && input < 9) {
		cout << "1. Load Weekly diet plan from file\n2. Load weekly excercise plan from file\n3. Store weekly diet plan to file\n4. Store weekly excercise plan to file\n5. Display weekly diet plan to screen\n6. Display weekly excercise plan to screen\n7. Edit daily diet plan\n8. Edit daily excercise plan\n9. Exit\nEnter menu option: ";
		cin >> input;
		if (input == 1) {
			loadWeeklyPlan(dPlan);
			if (dPlan[0].getName() == "")
				cout << "Did not succesfully load weekly diet plan\n";
			else
				cout << "Succesfully loaded weekly diet plan\n";
		}
		else if (input == 2) {
			loadWeeklyPlan(ePlan);
			if (dPlan[0].getName() == "")
				cout << "Did not succesfully load weekly excercise plan\n";
			else
				cout << "Succesfully loaded weekly excercise plan\n";
		}
		else if (input == 3) {
			if (dPlan[0].getName() != "")
				storeWeeklyPlan(dPlan);
		}
		else if (input == 4) {
			if (ePlan[0].getName() != "")
				storeWeeklyPlan(ePlan);
		}
		else if (input == 5)
			displayPlan(dPlan);
		else if (input == 6)
			displayPlan(ePlan);
		else if (input == 7) {
			int input2 = 0;
			while (input2 < 7) {
				system("pause");
				system("cls");
				for (int i = 1; i <= 7; i++)
					cout << i << ". " << dPlan[i-1];
				cout << "8: Exit\nEnter the plan to edit: ";
				cin >> input2;
				input2 -= 1;
				if (input2 >= 0 && input2 <= 6)
					dPlan[input2].editGoal();
			}
		}
		else if (input == 8) {
			int input2 = 0;
			while (input2 < 7) {
				system("pause");
				system("cls");
				for (int i = 1; i <= 7; i++)
					cout << i << ". " << ePlan[i-1];
				cout << "8: Exit\nEnter the plan to edit: ";
				cin >> input2;
				input2 -= 1;
				if (input2 >= 0 && input2 <= 6)
					ePlan[input2].editGoal();
			}
		}
		else{
			if(ePlan[0].getName()!="")
				storeWeeklyPlan(ePlan);
			if(dPlan[0].getName()!="")
				storeWeeklyPlan(dPlan);
			return;
		}
		system("pause");
		system("cls");
	}
}
void FitnessAppWrapper::displayPlan(DietPlan _dPlan[7]) {
	for (int i = 0; i < 7; i++)
		cout << _dPlan[i];
}
void FitnessAppWrapper::displayPlan(ExcercisePlan _ePlan[7]) {
	for (int i = 0; i < 7; i++)
		cout << _ePlan[i];
}
void FitnessAppWrapper::storeDailyPlan(DietPlan &dietPlan) {
	fDiet << dietPlan;
}
void FitnessAppWrapper::storeDailyPlan(ExcercisePlan &excercisePlan) {
	fExcercise << excercisePlan;
}
void FitnessAppWrapper::storeWeeklyPlan(DietPlan _dPlan[7]) {
	fDiet.open("diet.txt",fstream::out);
	for (int i = 0; i < 7; i++)
		storeDailyPlan(_dPlan[i]);
	fDiet.close();
}
void FitnessAppWrapper::storeWeeklyPlan(ExcercisePlan _ePlan[7]) {
	fExcercise.open("excercise.txt",fstream::out);
	for (int i = 0; i < 7; i++)
		storeDailyPlan(_ePlan[i]);
	fExcercise.close();
}
void FitnessAppWrapper::loadDailyPlan(DietPlan &dietPlan) {
	fDiet >> dietPlan;
}
void FitnessAppWrapper::loadDailyPlan(ExcercisePlan &excercisePlan) {
	fExcercise >> excercisePlan;
}
void FitnessAppWrapper::loadWeeklyPlan(DietPlan _dPlan[7]) {
	fDiet.open("diet.txt",fstream::in);
	for (int i = 0; i < 7; i++)
		loadDailyPlan(_dPlan[i]);
	fDiet.close();
}
void FitnessAppWrapper::loadWeeklyPlan(ExcercisePlan _ePlan[7]) {
	fExcercise.open("excercise.txt",fstream::in);
	for (int i = 0; i < 7; i++)
		loadDailyPlan(_ePlan[i]);
	fExcercise.close();
}