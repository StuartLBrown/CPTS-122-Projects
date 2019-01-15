#include "fitbit.h"
int main(void) {
	FILE *infile = fopen("FitbitData.csv", "r");
	char *patient = getPatient(infile);
}