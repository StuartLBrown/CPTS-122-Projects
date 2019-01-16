#include "fitbit.h"
int main(void) {
	FILE *infile = fopen("FitbitData.csv", "r");
	char patient[7];
	strcpy(patient,getPatient(infile));
	readLine(infile, patient);
}