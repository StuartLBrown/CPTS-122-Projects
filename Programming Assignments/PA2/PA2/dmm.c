#include "dmm.h"
void menu(FILE *infile) {
	printf("1.Load\n2.Store\n3.Display\n4.Insert\n5.Delete\n6.Edit\n7.Sort\n8.Rate\n9.Play\n10.Shuffle\n11.Exit\nEnter your option: ");
	int input = 0;
	scanf("%d", &input);
	Node *list = NULL;
	while (input != 11) {
		if (input == 1) {
			if (load(infile, &list))
				printf("Succesfully loaded songs into list\n");
		}
		else if (input == 2)
			store(infile, list);
		else if (input == 3) {
			printf("1.Display all songs\n2.Display all songs by a specific artist\nEnter your option: ");
			scanf("%d", &input);
			if (input != 2) {
				display(list, NULL);
			}
			else {
				printf("Enter an artists name (note it is case sensitive): ");
				char name[20];
				fgets(name, 20, stdin);
				display(list, name);
			}
		}
		//else if (input == 4)
			//insert
		//else if (input == 5)
			//delete
		//else if (input == 6)
			//edit();
		//else if (input == 7)
			//sort
		//else if (input == 8)
			//rate();
		//else if (input == 9)
			//play();
		//else if (input == 10)
			//shuffle
		else {
			//exit/bad input
			return;
		}
		system("pause");
		system("cls");
		printf("1.Load\n2.Store\n3.Display\n4.Insert\n5.Delete\n6.Edit\n7.Sort\n8.Rate\n9.Play\n10.Shuffle\n11.Exit\nEnter your option: ");
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
			if (*line == '\0'||*line=='\n')
				break;
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
		if ((*list) != NULL)
			(*list)->prev = temp;
		*list = temp;
		return 1;
	}
	return 0;
}
void display(Node *list, char *artist) {
	while (list != NULL) {
		Record temp = list->song;
		if (artist == NULL || strcmp(temp.artist, artist) == 0) {
			printf("Artist: %s | Album: %s | Title: %s | Genre: %s | Duration: %d:%d | Times Played: %d | Rating: %d\n\n", temp.artist, temp.album, temp.title, temp.genre, temp.duration.mins, temp.duration.secs, temp.timesPlayed, temp.rating);
		}
		list = list->next;
	}
}
int store(FILE *file, Node *list) {
	file = fopen("musicPlayList.csv", "w");
	if (file != NULL) {
		while (list != NULL) {
			Record temp = list->song;
			fprintf(file,"\"%s\",%s,%s,%s,%d:%d,%d,%d\n", temp.artist, temp.album, temp.title, temp.genre, temp.duration.mins, temp.duration.secs, temp.timesPlayed, temp.rating);
			list = list->next;
		}
		fclose(file);
		return 1;
	}
	return 0;
}