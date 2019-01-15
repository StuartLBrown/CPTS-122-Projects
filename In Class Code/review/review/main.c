#include "review.h"
int main(int argc, char *argv[]) {
	FILE *file = fopen("data.csv", "r");
	if (file != NULL) {
		char line[100];
		Student data[1440] = { {0,"",""} };
		fgets(line, 100, file);
		puts(line);
		//puts the null character for every instance of the comma in line (strtok)
		//atoi converts a string to an int
		data[0].id = atoi(strtok(line, ","));
		strcpy(data[0].name,strtok(NULL, ","));
		strcpy(data[0].major, strtok(NULL, ","));
		puts(data->major);
	}
	return 0;
}