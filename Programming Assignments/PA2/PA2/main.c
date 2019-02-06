#include "tests.h"
int main(void) {
	FILE *file = fopen("musicPlayList.csv", "r");
	srand((unsigned int)time(NULL));
	//test_delete();
	menu(file);
	fclose(file);
	return 0;
}