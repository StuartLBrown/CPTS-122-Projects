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
int calc_max(FitBitData data[1500]) {
	int max = -10;
	for (int i = 0; i < 1500; i++) {
		if (data[i].steps > max)
			max = data[i].steps;
	}
	return max;
}