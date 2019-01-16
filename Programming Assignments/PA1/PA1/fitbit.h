#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef enum {
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
}Sleep;
typedef struct {
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
}FitBitData;
typedef struct {
	double totalDistance;
	double totalCalories;
	int floorsWalked;
	int totalSteps;
	int averageHeartRate;
	int maxStepsInOneMinute;
	char startMinute[9];
	char endMinute[9];
}Stats;
FitBitData readLine(FILE *file, char *patient);
char *getPatient(FILE *file);
void test(char *test);
void printData(FitBitData data);
//returns 0 if valid, 1-8 depending on which entry is bad
int verifyLine(char *line);
void readBadLine(FitBitData *data, char *line, int badData);
void writeStats(FILE *file, Stats stats);
Stats calcStats(FitBitData *data, int size, char *patient);
void writeDataToFile(FitBitData *data, int size, FILE *file);