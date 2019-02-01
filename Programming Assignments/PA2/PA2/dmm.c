#include "dmm.h"
void menu(FILE *infile) {
	printf("1.Load\n2.Store\n3.Display\n4.Insert\n5.Delete\n6.Edit\n7.Sort\n8.Rate\n9.Play\n10.Shuffle\n11.Exit\nEnter your option: ");
	int input = 0;
	scanf("%d", &input);
	Node *list = NULL;
	while (input !=11) {
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
				system("cls");
				display(list, NULL);
			}
			else {
				printf("Enter an artists name (note it is case sensitive): ");
				char name[20];
				scanf(" %s", name);
				system("cls");
				display(list, name);
			}
		}
		//else if (input == 4)
			//insert
		//else if (input == 5)
			//delete
		else if (input == 6) {
			printf("Enter an artists name (note it is case sensitive): ");
			char name[20];
			scanf(" %s", name);
			edit(&list, name);
		}
		//else if (input == 7)
			//sort
		//else if (input == 8)
			//rate();
		else if (input == 9)
			play(list);
		//else if (input == 10)
			//shuffle
		else if (input == 11) {
			//exit (same thing as store)
			store(infile, list);
		}
		else {
			store(infile, list);
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
			displayRecord(temp);
		}
		list = list->next;
	}
}
int store(FILE *file, Node *list) {
	file = fopen("musicPlayList.csv", "w");
	if (file != NULL) {
		while (list->next != NULL)
			list = list->next;
		Record temp = list->song;
		fprintf(file, "\"%s\",%s,%s,%s,%d:%d,%d,%d", temp.artist, temp.album, temp.title, temp.genre, temp.duration.mins, temp.duration.secs, temp.timesPlayed, temp.rating);
		list = list->prev;
		while (list != NULL) {
			temp = list->song;
			fprintf(file,"\n\"%s\",%s,%s,%s,%d:%d,%d,%d", temp.artist, temp.album, temp.title, temp.genre, temp.duration.mins, temp.duration.secs, temp.timesPlayed, temp.rating);
			list = list->prev;
		}
		fclose(file);
		return 1;
	}
	return 0;
}
void edit(Node **list, char *artist) {
	int count = 0, indices[100], index=0;
	Node *temp = *list;
	while (temp->next != NULL) {
		if (strcmp(temp->song.artist, artist) == 0) {
			if (count > 0)
				indices[count] = index-indices[0];
			else
				indices[count] = index;
			count++;
		}
		temp = temp->next;
		index++;
	}
	if (strcmp(temp->song.artist, artist) == 0) {
		if (count > 0)
			indices[count] = index - indices[0];
		else
			indices[count] = index;
		count++;
	}
	while (temp->prev != NULL)
		temp = temp->prev;
	if (count == 0) {
		printf("No artists found by that name!\n");
		return;
	}
	else if (count == 1) {
		for (int i = 0; i < indices[0]; i++) {
			temp = temp->next;
		}
		int input = 0;
		while (input != 8) {
			printf("Edit Record:\n1.Artist\n2.Album\n3.Song\n4.Genre\n5.Song Length\n6.Number of times played\n7.Rating\n8.Done\nEnter your choice: ");
			scanf("%d", &input);
			if(input!=8)
				editRecord(&(temp->song), input);
		}
	}
	else {
		printf("Enter the number of which song to edit:\n");
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < indices[i]; j++)
				temp = temp->next;
			printf("%d. ", i+1);
			displayRecord(temp->song);
		}
		int input = 0;
		scanf("%d", &input);
		while (input <= 0 || input > count) {
			printf("Invalid input try again: ");
			scanf("%d", &input);
		}
		while ((temp)->prev != NULL)
			temp = temp->prev;
		if (input == 1) {
			for (int i = 0; i < indices[input-1]; i++) {
				temp = temp->next;
			}
		}
		else {
			for (int i = 0; i < indices[0] + indices[input-1]; i++) {
				temp = temp->next;
			}
		}
		input = 0;
		system("cls");
		while (input != 8) {
			printf("Edit Record:\n1.Artist\n2.Album\n3.Song\n4.Genre\n5.Song Length\n6.Number of times played\n7.Rating\n8.Done\nEnter your choice: ");
			scanf("%d", &input);
			if(input!=8)
				editRecord(&(temp->song), input);
		}
	}
}
void displayRecord(Record r) {
	printf("Artist: %s | Album: %s | Title: %s | Genre: %s | Duration: %d:%d | Times Played: %d | Rating: %d\n\n", r.artist, r.album, r.title, r.genre, r.duration.mins, r.duration.secs, r.timesPlayed, r.rating);
}

void editRecord(Record *r, int attribute) {
	displayRecord(*r);
	if (attribute == 1) {
		printf("Enter a new artist: ");
		char artist[20];
		scanf(" %s", artist);
		strcpy(r->artist, artist);
	}
	else if (attribute == 2) {
		printf("Enter a new album title: ");
		char album[25];
		scanf(" %s", album);
		strcpy(r->album, album);
	}
	else if (attribute == 3) {
		printf("Enter a new song title: ");
		char song[15];
		scanf(" %s", song);
		strcpy(r->title, song);
	}
	else if (attribute == 4) {
		printf("Enter a new genre: ");
		char genre[15];
		scanf(" %s", genre);
		strcpy(r->genre, genre);
	}
	else if (attribute == 5) {
		printf("Enter a new duration of the song in mins and secs: ");
		Duration d;
		scanf("%d%d", &(d.mins), &(d.secs));
		r->duration = d;
	}
	else if (attribute == 6) {
		printf("Enter the a new number of times played: ");
		int n = 0;
		scanf("%d", &n);
		r->timesPlayed = n;
	}
	else if (attribute == 7) {
		printf("Enter the a new rating: ");
		int rating = 0;
		scanf("%d", &rating);
		r->rating = rating;
	}
	else
		return;
}
void play(Node *list) {
	system("cls");
	Node *temp = list;
	int count=1, index = 0;
	while (list != NULL) {
		printf("%d. ",count);
		displayRecord(list->song);
		count++;
		list = list->next;
	}
	printf("Select a song to start from: ");
	scanf("%d", &index);
	while (index <= 0 || index > count) {
		printf("Incorrect song to start from, try again");
		scanf("%d", &index);
	}
	system("cls");
	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}
	for (int i = index; i < count; i++) {
		displayRecord(temp->song);
		system("pause");
		system("cls");
		temp = temp->next;
	}
}
void rate(Node **list) {

}