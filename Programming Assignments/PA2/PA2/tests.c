#include "tests.h"
void test_insert(void) {
	Node *temp = { NULL };
	Duration d = { 4,36 };
	Record song = { "Perry,Katy","Witness","Chained in the Rhythm","pop",d,-1,6 };
	if (temp == NULL) {
		insertAtFront(&temp, song);
		if (temp == NULL) {
			song.timesPlayed = 5;
			song.rating = 3;
			insertAtFront(&temp, song);
			if (temp->song.duration.secs = song.duration.secs) {
				printf("Passed insert at front\n");
			}
		}
	}
}
void test_delete(void) {
	Node *temp = { NULL };
	Duration d = { 4,36 };
	Record song = { "Perry,Katy","Witness","Chained in the Rhythm","pop",d,3,5 };
	insertAtFront(&temp, song);
	if (temp != NULL) {
		deleteRecord(&temp, "Chained in the Rhythm");
		if (temp == NULL)
			printf("Passed delete\n");
	}
}