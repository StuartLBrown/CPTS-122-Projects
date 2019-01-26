#include "dmm.h"
void menu(FILE *infile) {
	printf("1.Load\n2.Store\n3.Display\n4.Insert\n5.Delete\n6.Edit\n7.Sort\n8.Rate\n9.Play\n10.Shuffle\n11.Exit\nEnter your option: ");
	int input = 0;
	scanf("%d", &input);
	Node *list = NULL;
	while (input != 11) {
		switch (input) {
		case 1:
			load(infile, &list);
		case 2:
			//store();
		case 3:
			//display();
		case 4:
			//insert
		case 5:
			//delete
		case 6:
			//edit();
		case 7:
			//sort
		case 8:
			//rate();
		case 9:
			//play();
		case 10:
			//shuffle
		default:
			//exit/bad input
			return;
		}
		printf("1. Load\n2.Store\n3.Display\n4.Insert\n5.Delete\n6.Edit\n7.Sort\n8.Rate\n9.Play\n10.Shuffle\n11.Exit\nEnter your option: ");
		scanf("%d", &input);
	}
}
int load(FILE *infile, Node **list) {
	int success = 0;
	if (infile != NULL) {
		Record temp;
		while (!feof(infile)) {
			char line[150];
			fgets(line, 150, infile);
			if (*line == '\"') {
				strcpy(temp.artist, strtok(line + 1, "\""));
			}
			else
				strcpy(temp.artist, strtok(line, ","));
			strcpy(temp.album, strtok(NULL, ","));
			strcpy(temp.title, strtok(NULL, ","));
			strcpy(temp.genre, strtok(NULL, ","));
			temp.duration.mins = atoi(strtok(NULL, ":"));
			temp.duration.secs = atoi(strtok(NULL, ","));
			temp.timesPlayed = atoi(strtok(NULL, ","));
			temp.rating = atoi(strtok(NULL, "\n"));
			insertAtFront(list, temp);
		}
		success = 1;
		printList(*list);
	}
	return success;
}
Node *makeNode(Record data) {
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->next = NULL;
	temp->prev = NULL;
	temp->song = data;
	return temp;
}
int insertAtFront(Node **list, Record data) {
	Node *temp = NULL;
	temp = makeNode(data);
	if (temp != NULL) {
		temp->next = *list;
		temp->prev = NULL;
		*list = temp;
		temp->prev = list;
		return 1;
	}
	return 0;
}
void printList(Node *list) {
	while (list != NULL) {
		Record temp = list->song;
		printf("Artist: %s | Album: %s | Title: %s | Genre: %s | Duration: %d:%d | Times Played: %d | Rating: %d\n\n", temp.artist, temp.album, temp.title, temp.genre, temp.duration.mins, temp.duration.secs, temp.timesPlayed, temp.rating);
		list = list->next;
	}
}