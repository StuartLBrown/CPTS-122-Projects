#include "fitbit.h"
FitBitData readLine(FILE *file, char *patient) {
	FitBitData data;
	if (patient != NULL && file != NULL) {
		char line[100], copy[100];
		fgets(line, 100, file);
		strcpy(copy, line);
		strtok(line, ",");
		char temp[20];
		strcpy(temp, line);
		if (*temp != '\0'&&strcmp(temp, patient) == 0) {
			strcpy(data.patient, patient);
			int verify = verifyLine(copy);
			if (verify == 0) {
				strcpy(data.minute, strtok(NULL, ","));
				data.calories = atof(strtok(NULL, ","));
				data.distance = atof(strtok(NULL, ","));
				data.floors = atoi(strtok(NULL, ","));
				data.heartRate = atoi(strtok(NULL, ","));
				data.steps = atoi(strtok(NULL, ","));
				data.sleepLevel = atoi(strtok(NULL, ","));
			}
			else {
				readBadLine(&data, copy, verify);
			}
		}
		else {
			strcpy(data.patient, "ERROR");
			strcpy(data.minute, "ERROR");
			data.calories = -1;
			data.distance = -1;
			data.floors = -1;
			data.heartRate = -1;
			data.sleepLevel = -1;
			data.steps = -1;
		}
	}
	return data;
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
	strcpy(line, strchr(line, ','));
	char patient[6];
	strtok(line, ",");
	if (*(line) == '\0')
		return NULL;
	strcpy(patient, line + 1);
	fgets(line, 100, file);
	return patient;
}
void printData(FitBitData data) {
	printf("Patient: %s\nMinute: %s\n", data.patient, data.minute);
	printf("Calories: %lf\nDistance: %lf\nFloors: %d\nHeart Rate: %d\nSteps: %d\nSleep Level: %d\n", data.calories, data.distance, data.floors, data.heartRate, data.steps, data.sleepLevel)
		;
}
//returns 0 if line is good, 1-6 if that entry is bad (should ignore it) 
int verifyLine(char *line) {
	int count = 0, index = 0;
	while (count < 7) {
		if (*(line + index) == ',') {
			count++;
			if (*(line + index - 1) == ',')
				return count;
			if (*(line + index + 1) == ',')
				return count;
		}
		index++;
	}
	return 0;
}
void readBadLine(FitBitData *data, char *line, int badData) {
	strtok(line, ",");
	if (badData == 2) {
		strcpy(data->minute, "ERROR");
		data->calories = atof(strtok(NULL, ","));
		data->distance = atof(strtok(NULL, ","));
		data->floors = atoi(strtok(NULL, ","));
		data->heartRate = atoi(strtok(NULL, ","));
		data->steps = atoi(strtok(NULL, ","));
		data->sleepLevel = atoi(strtok(NULL, ","));
	}
	else if (badData == 3) {
		strcpy(data->minute, strtok(NULL,","));
		data->calories = -1;
		data->distance = atof(strtok(NULL, ","));
		data->floors = atoi(strtok(NULL, ","));
		data->heartRate = atoi(strtok(NULL, ","));
		data->steps = atoi(strtok(NULL, ","));
		data->sleepLevel = atoi(strtok(NULL, ","));
	}
	else if (badData == 4) {
		strcpy(data->minute, strtok(NULL, ","));
		data->calories = atof(strtok(NULL, ","));
		data->distance = -1;
		data->floors = atoi(strtok(NULL, ","));
		data->heartRate = atoi(strtok(NULL, ","));
		data->steps = atoi(strtok(NULL, ","));
		data->sleepLevel = atoi(strtok(NULL, ","));
	}
	else if (badData == 5) {
		strcpy(data->minute, strtok(NULL, ","));
		data->calories = atof(strtok(NULL, ","));
		data->distance = atof(strtok(NULL, ","));
		data->floors = -1;
		data->heartRate = atoi(strtok(NULL, ","));
		data->steps = atoi(strtok(NULL, ","));
		data->sleepLevel = atoi(strtok(NULL, ","));
	}
	else if (badData == 6) {
		strcpy(data->minute, strtok(NULL, ","));
		data->calories = atof(strtok(NULL, ","));
		data->distance = atof(strtok(NULL, ","));
		data->floors = atoi(strtok(NULL, ","));
		data->heartRate = -1;
		data->steps = atoi(strtok(NULL, ","));
		data->sleepLevel = atoi(strtok(NULL, ","));
	}
	else if (badData == 7) {
		strcpy(data->minute, strtok(NULL, ","));
		data->calories = atof(strtok(NULL, ","));
		data->distance = atof(strtok(NULL, ","));
		data->floors = atoi(strtok(NULL, ","));
		data->heartRate = atoi(strtok(NULL, ","));
		data->steps = -1;
		data->sleepLevel = atoi(strtok(NULL, ","));
	}
}
void writeStats(FILE *file, Stats stats) {
	fprintf(file, "Total Calories Burned,Total Distance Walked(miles),Total Floors,Total Steps Taken,Average Heartrate,Max Steps in One Minute,Sleep Stats\n");
	fprintf(file, "%.2lf,%.2lf,%d,%d,%d,%d,%s:%s\n", stats.totalCalories, stats.totalDistance, stats.floorsWalked, stats.totalSteps, stats.averageHeartRate, stats.maxStepsInOneMinute, stats.startMinute, stats.endMinute);
}
Stats calcStats(FitBitData *data, int size, char *patient) {
	Stats stats;
	int totalF = 0, totalS = 0, avgHR = 0, maxSM = data->steps, totalH = 0, range=0, maxRange=0, lengthRange=0, index=0, maxRangeLength=0;
	double totalC = 0, totalD = 0;
	for (int i = 0; i <= size; i++) {
		if (strcmp((data + i)->patient, patient) == 0) {
			if ((data + i)->calories != -1)
				totalC += (data + i)->calories;
			if ((data + i)->distance != -1)
				totalD += (data + i)->distance;
			if ((data + i)->floors != -1)
				totalF += (data + i)->floors;
			if ((data + i)->steps != -1)
				totalS += (data + i)->steps;
			if ((data + i)->heartRate != -1)
				totalH += (data + i)->heartRate;
			if ((data + i)->steps > maxSM) {
				maxSM = (data + i)->steps;
			}
			if ((data + i)->sleepLevel > 1) {
				lengthRange++;
				range += (data + i)->sleepLevel;
				if (range > maxRange) {
					maxRange = range;
					maxRangeLength = lengthRange;
					index = i;
				}
			}
			else {
				lengthRange = 0;
				range = 0;
			}
		}
	}
	avgHR = totalH / (size+1);
	stats.averageHeartRate = avgHR;
	stats.floorsWalked = totalF;
	stats.totalCalories = totalC;
	stats.totalDistance = totalD;
	stats.totalSteps = totalS;
	stats.maxStepsInOneMinute = maxSM;
	strcpy(stats.startMinute, (data + index - maxRangeLength+1)->minute);
	strcpy(stats.endMinute, (data + index)->minute);
	return stats;
}
void writeDataToFile(FitBitData *data, int size, FILE *file) {
	fputs("Target: ,12cx7,,,,,,\nPatient,minute,calories,distance,floors,heart,steps,sleep_level\n",file);
	for (int i = 0; i < size;i++) {
		if (strcmp((data + i)->patient, "ERROR") != 0) {
			fprintf(file, "%s,%s,%.2lf,%.2lf,%d,%d,%d,%d\n", (data + i)->patient, (data + i)->minute, (data + i)->calories, (data + i)->distance, (data + i)->floors, (data + i)->heartRate, (data + i)->steps, (data + i)->sleepLevel);
		}
	}
}