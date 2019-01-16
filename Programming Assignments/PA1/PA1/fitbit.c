#include "fitbit.h"
FitBitData null = NULL;
FitBitData readLine(FILE *file, char *patient) {
	if (patient != NULL && file != NULL) {
		FitBitData data;
		char line[100];
		fgets(line, 100, file);
		strtok(line, ",");
		char temp[20];
		strcpy(temp, line);
		if (*temp != '\0'&&strcmp(temp,patient)==0) {
			strcpy(data.patient, patient);

		}
		return data;
	}
	return null;
}
void test(char *test) {
	puts(test);
}
//function getPatient takes the file given, returns the patient value
//if no patient value is found then it return null
//also reads the second line since it is only used for formatting purposes
//@param *file takes the file in read mode and reads the first 2 lines, must be in .csv format
char *getPatient(FILE *file) {
	char line[100];
	fgets(line, 100, file);
	strcpy(line,strchr(line, ','));
	char patient[6];
	strtok(line, ",");
	if (*(line)=='\0')
		return NULL;
	strcpy(patient, line + 1);
	fgets(line, 100, file);
	return patient;
}