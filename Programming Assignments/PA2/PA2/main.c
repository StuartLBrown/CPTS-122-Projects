#include "tests.h"
int main(void) {
	FILE *file = fopen("musicPlayList.csv", "r");
	test_delete();
	//menu(file);
	fclose(file);
	return 0;
}