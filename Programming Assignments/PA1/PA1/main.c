#include "fitbit.h"
int main(void) {
	FILE *infile = fopen("FitbitData.csv", "r"), *outfile = fopen("Results.csv","w");
	char patient[7];
	strcpy(patient,getPatient(infile));
	FitBitData data[1500];
	int i = 0;
	while (!feof(infile)) {
		data[i] = readLine(infile, patient);
		i++;
	}
	Stats s = calcStats(data, i-2,patient);
	writeStats(outfile, s);
	writeDataToFile(data, i-2, outfile);
	fclose(infile);
	fclose(outfile);
}