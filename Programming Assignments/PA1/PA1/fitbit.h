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
FitBitData readLine(FILE *file, char *patient);
char *getPatient(FILE *file);
void test(char *test);