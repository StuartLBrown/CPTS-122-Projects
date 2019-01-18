#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef enum {
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
}Sleep;
//storing the patient data
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
//storing the stats
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
//reads one line of the data and scrubs it
FitBitData readLine(FILE *file, char *patient);
//gets the patient from the file (file must start at the beginning (no lines read))
char *getPatient(FILE *file);
//returns 0 if valid, 1-8 depending on which entry is bad
int verifyLine(char *line);
//takes the bad data line from verify line and fills in the corresponding data
void readBadLine(FitBitData *data, char *line, int badData);
//writes all the stats to the file
void writeStats(FILE *file, Stats stats);
//calculates and returns the stats based on the data and the patient
Stats calcStats(FitBitData *data, int size, char *patient);
//writes the entire data array to the file after the stats have been calculated
void writeDataToFile(FitBitData *data, int size, FILE *file);