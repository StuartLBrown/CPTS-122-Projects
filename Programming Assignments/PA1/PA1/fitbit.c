#include "fitbit.h"
//reads one line of the data and scrubs it
FitBitData readLine(FILE *file, char *patient) {
	FitBitData data;
	if (patient != NULL && file != NULL) {
		//storage variables for the line
		char line[100], copy[100];
		fgets(line, 100, file);
		//uses a unedited copy of the line for use for checking which data values are bad
		strcpy(copy, line);
		//starting the tokeniser for splitting the line into chunks
		strtok(line, ",");
		//first entry (patient)
		char temp[20];
		strcpy(temp, line);
		//checking if the patient matches the one given
		if (*temp != '\0'&&strcmp(temp, patient) == 0) {
			strcpy(data.patient, patient);
			//verifying if the whole line is good or if there is bad data contained in it
			int verify = verifyLine(copy);
			if (verify == 0) {
				//no bad data case
				strcpy(data.minute, strtok(NULL, ","));
				data.calories = atof(strtok(NULL, ","));
				data.distance = atof(strtok(NULL, ","));
				data.floors = atoi(strtok(NULL, ","));
				data.heartRate = atoi(strtok(NULL, ","));
				data.steps = atoi(strtok(NULL, ","));
				data.sleepLevel = atoi(strtok(NULL, ","));
			}
			else {
				//bad data case
				readBadLine(&data, copy, verify);
			}
		}
		//patient is bad, whole data line is bad
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
//gets the patient from the file (file must start at the beginning (no lines read))
char *getPatient(FILE *file) {
	char line[100];
	fgets(line, 100, file);
	strtok(line, ",");
	char patient[6];
	//getting the patient
	strcpy(patient,strtok(NULL, ","));
	//reading the next line (don't need it)
	fgets(line, 100, file);
	return patient;
}
//returns 0 if line is good, 1-7 if that entry is bad (should ignore it) 
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
//takes the bad data line from verify line and fills in the corresponding data
void readBadLine(FitBitData *data, char *line, int badData) {
	//first part (patient) - already verified and put in
	strtok(line, ",");
	//each of these are cases where the data is either fine or not fine (-1 means bad data and is not recorded when it comes to stats)
	if (badData == 2)
		strcpy(data->minute, "ERROR");
	else
		strcpy(data->minute, strtok(NULL, ","));
	if (badData == 3)
		data->calories = -1;
	else
		data->calories = atof(strtok(NULL, ","));
	if (badData == 4)
		data->distance = -1;
	else
		data->distance = atof(strtok(NULL, ","));
	if (badData == 5)
		data->floors = -1;
	else
		data->floors = atoi(strtok(NULL, ","));
	if (badData == 6)
		data->heartRate = -1;
	else
		data->heartRate = atoi(strtok(NULL, ","));
	if (badData == 7)
		data->steps = -1;
	else
		data->steps = atoi(strtok(NULL, ","));
	data->sleepLevel = atoi(strtok(NULL, ","));
}
//writes all the stats to the file
void writeStats(FILE *file, Stats stats) {
	fprintf(file, "Total Calories Burned,Total Distance Walked(miles),Total Floors,Total Steps Taken,Average Heartrate,Max Steps in One Minute,Sleep Stats\n");
	fprintf(file, "%.2lf,%.2lf,%d,%d,%d,%d,%s:%s\n", stats.totalCalories, stats.totalDistance, stats.floorsWalked, stats.totalSteps, stats.averageHeartRate, stats.maxStepsInOneMinute, stats.startMinute, stats.endMinute);
}
//calculates and returns the stats based on the data and the patient
Stats calcStats(FitBitData *data, int size, char *patient) {
	Stats stats;
	//variables for all the stats (total floors, total steps, average heart rate, max steps/min, total heart rate (for use in average heart rate), range is for finding the period of poorest sleep, maxRange - basically the max of range, lengthRange - just for storage, index for the start of the range of poor sleep, maxRangeLength - basically the max of length range)
	int totalF = 0, totalS = 0, avgHR = 0, maxSM = data->steps, totalH = 0, range=0, maxRange=0, lengthRange=0, index=0, maxRangeLength=0;
	//total calories, total distance
	double totalC = 0, totalD = 0;
	//looping through the entire array
	for (int i = 0; i <= size; i++) {
		//if the patient is incorrect, dont use the line
		if (strcmp((data + i)->patient, patient) == 0) {
			//if any of the data = -1 (i.e. bad data) don't use it for stats
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
			//calculating the range of poorest sleep
			if ((data + i)->sleepLevel > 1) {
				//length of range is not used in calculation
				lengthRange++;
				//total "range"/ total for the poor sleep
				range += (data + i)->sleepLevel;
				//setting the maxes + index
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
	//average heart rate
	avgHR = totalH / (size+1);
	//setting the values to the struct
	stats.averageHeartRate = avgHR;
	stats.floorsWalked = totalF;
	stats.totalCalories = totalC;
	stats.totalDistance = totalD;
	stats.totalSteps = totalS;
	stats.maxStepsInOneMinute = maxSM;
	//setting the starting + ending minute for the poorest sleep
	strcpy(stats.startMinute, (data + index - maxRangeLength+1)->minute);
	strcpy(stats.endMinute, (data + index)->minute);
	return stats;
}
//writes the entire data array to the file after the stats have been calculated
void writeDataToFile(FitBitData *data, int size, FILE *file) {
	//first line
	fputs("Target: ,12cx7,,,,,,\nPatient,minute,calories,distance,floors,heart,steps,sleep_level\n",file);
	for (int i = 0; i < size;i++) {
		//checking if the patient is incorrect (ignore that line)
		if (strcmp((data + i)->patient, "ERROR") != 0) {
			fprintf(file, "%s,%s,%.2lf,%.2lf,%d,%d,%d,%d\n", (data + i)->patient, (data + i)->minute, (data + i)->calories, (data + i)->distance, (data + i)->floors, (data + i)->heartRate, (data + i)->steps, (data + i)->sleepLevel);
		}
	}
}