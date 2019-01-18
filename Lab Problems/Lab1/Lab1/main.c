#include "lab1.h"
int main(void) {
	char str1[4] = "bac", str2[4] = "cae";
	char *temp = sortTwoStrings(str1, str2);
	puts(temp);
	return 0;
}