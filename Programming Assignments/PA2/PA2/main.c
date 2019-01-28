#include "dmm.h"
int main(void) {
	FILE *file = fopen("musicPlayList.csv", "r");
	menu(file);
	fclose(file);
	return 0;
}