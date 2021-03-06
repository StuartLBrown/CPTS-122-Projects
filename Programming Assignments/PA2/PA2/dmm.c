#include "dmm.h"
void menu(FILE *infile) {
	printf("1.Load\n2.Store\n3.Display\n4.Insert\n5.Delete\n6.Edit\n7.Sort\n8.Rate\n9.Play\n10.Shuffle\n11.Exit\nEnter your option: ");
	int input = 0;
	scanf("%d", &input);
	Node *list = NULL;
	while (1) {
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
		else if (input == 4)
			insert(&list);
		else if (input == 5) {
			char title[15];
			fseek(stdin, 0, SEEK_END);
			printf("Enter a song title: ");
			fgets(title, 15, stdin);
			strtok(title, "\n");
			deleteRecord(&list, title);
		}
		else if (input == 6) {
			printf("Enter an artists name (note it is case sensitive): ");
			char name[20];
			scanf(" %s", name);
			edit(&list, name);
		}
		else if (input == 7) {
			printf("Enter an attribute to sort by:\n1.Artist\n2.Album Title\n3.Rating\n4.Times played (largest-smallest)\n");
			int input = 0;
			scanf("%d", &input);
			while (input < 0 && input>4) {
				printf("Incorrect attribute try again: ");
				scanf("%d", &input);
			}
			system("cls");
			sortList(&list, input);
			display(list, NULL);
		}
		else if (input == 8)
			rate(&list);
		else if (input == 9)
			play(list);
		else if (input == 10) {
			shuffle(list, getSize(list), generatePositions(getSize(list)));
		}
		else if (input == 11) {
			//exit (same thing as store)
			store(infile, list);
			break;
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
	//if in invalid rating or timesplayed is passed into the list, don't put it in the list
	if (data.timesPlayed < 0 || data.rating < 1 || data.rating>5)
		return 0;
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
		char song[25];
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
		while (n < 0) {
			printf("Invalid times played: ");
			scanf("%d", &n);
		}
		r->timesPlayed = n;
	}
	else if (attribute == 7) {
		printf("Enter the a new rating: ");
		int rating = 0;
		scanf("%d", &rating);
		while (rating < 1 || rating>5) {
			printf("Invalid rating: ");
			scanf("%d", &rating);
		}
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
	Node *temp = *list;
	int count = 0, input = 0;
	while (input != count + 1) {
		count = 0;
		while (temp->next != NULL) {
			count++;
			printf("%d. ", count);
			displayRecord(temp->song);
			temp = temp->next;
		}
		count++;
		printf("%d. ", count);
		displayRecord(temp->song);
		printf("%d. Exit\n\n",count+1);
		printf("Enter a song to rate: ");
		scanf("%d", &input);
		while (input<1 && input>count + 1) {
			printf("Invalid song try again: ");
			scanf("%d", &input);
		}
		if (input != count + 1) {
			for (int i = count; i > input; i--)
				temp = temp->prev;
			editRecord(&(temp->song), 7);
			while (temp->prev != NULL)
				temp = temp->prev;
		}
	}
}
int insert(Node **list) {
	Record r;
	printf("Enter an artists name: ");
	scanf(" %s", r.artist);
	printf("Enter an album title: ");
	scanf(" %s", r.album);
	printf("Enter the song title: ");
	scanf(" %s", r.title);
	printf("Enter the genre of the song: ");
	scanf(" %s", r.genre);
	printf("Enter the song length in minutes: ");
	scanf("%d", &(r.duration.mins));
	printf("Enter the song length in seconds: ");
	scanf("%d", &(r.duration.secs));
	printf("Enter the song's rating: ");
	scanf("%d", &(r.rating));
	printf("Enter the number of times the song has been played: ");
	scanf("%d", &(r.timesPlayed));
	return insertAtFront(list, r);
}
int deleteRecord(Node **list, char *title) {
	Node *temp = *list;
	while (temp != NULL) {
		if (strcmp(temp->song.title, title) == 0) {
			if (temp->prev == NULL) {
				*list = temp->next;
				free(temp);
				return 1;
			}
			else if (temp->next == NULL) {
				temp->prev->next = NULL;
				free(temp);
				return 1;
			}
			else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				free(temp);
				return 1;
			}
		}
		temp = temp->next;
	}
	return 0;
}
int getSize(Node *list) {
	int size = 0;
	for (; list != NULL; size++)
		list = list->next;
	return size;
}
void shuffle(Node *list, int size, int *order) {
	system("cls");
	int curP = *order, index = 0;
	while (index < size) {
		if (index != 0)
			curP = curP - *(order + index - 1);
		if (curP > 0) {
			for (int i = 0; i < curP; i++)
				list = list->next;
		}
		else {
			for (int i = 0; i > curP; i--)
				list = list->prev;
		}
		displayRecord(list->song);
		system("pause");
		system("cls");
		index++;
		curP = *(order + index);
	}
}
int *generatePositions(int size) {
	int *vals = (int*)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++) {
		*(vals + i) = i;
	}
	for (int i = 0; i < size * 3; i++) {
		int i1 = rand() % size, i2 = rand() % size;
		int temp = *(vals + i1);
		*(vals + i1) = *(vals + i2);
		*(vals + i2) = temp;
	}
	return vals;
}
void sortList(Node **list, int attribute) {
	int size = getSize(*list);
	Node *curr = *list;
	for (int i = 0; i < size; i++) {
		Node *temp = curr->next, *min = curr;
		for (int j = i + 1; j < size; j++) {
			if (temp != NULL) {
				if (attribute == 1 && strcmp(temp->song.artist, min->song.artist) < 0)
					min = temp;
				else if (attribute == 2 && strcmp(temp->song.album, min->song.album) < 0)
					min = temp;
				else if (attribute == 3 && temp->song.rating < min->song.rating)
					min = temp;
				else if (attribute == 4 && temp->song.timesPlayed > min->song.timesPlayed)
					min = temp;
				temp = temp->next;
			}
		}
		swap(&curr, &min);
		curr = curr->next;
	}
}
void swap(Node **list1, Node **list2) {
	Record temp = (*list1)->song;
	(*list1)->song = (*list2)->song;
	(*list2)->song = temp;
}