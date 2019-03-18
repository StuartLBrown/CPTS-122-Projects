#include "BST.h"
#include <math.h>
int main(void) {
	char randString[39] = "ABCDEFGHIJKLMNOPQRSUVWXYZ0123456789.,?";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 38; j++) {
			int rand1 = rand() % 38, rand2 = rand()%38;
			char temp = *(randString + rand1);
			*(randString + rand1) = *(randString + rand2);
			*(randString + rand2) = temp;
		}
	}
	puts(randString);
	return 0;
}