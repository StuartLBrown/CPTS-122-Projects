#include "dmm.h"
void menu(FILE *infile) {
	printf("1.Load\n2.Store\n3.Display\n4.Insert\n5.Delete\n6.Edit\n7.Sort\n8.Rate\n9.Play\n10.Shuffle\n11.Exit\nEnter your option: ");
	int input = 0;
	scanf("%d", &input);
	Node *list = NULL;
	//input loop - runs until exit is called
	while (1) {
		//load command
		if (input == 1) {
			if (load(infile, &list))
				printf("Succesfully loaded songs into list\n");
		}
		//store command
		else if (input == 2)
			store(infile, list);
		//display command
		else if (input == 3) {
			printf("1.Display all songs\n2.Display all songs by a specific artist\nEnter your option: ");
			scanf("%d", &input);
			//general case (display all songs)
			if (input != 2) {
				system("cls");
				display(list, NULL);
			}
			//specific case (only display songs by a specific artist)
			else {
				printf("Enter an artists name (note it is case sensitive): ");
				char name[20];
				scanf(" %s", name);
				system("cls");
				display(list, name);
			}
		}
		//insert command
		else if (input == 4)
			insert(&list);
		//delete command
		else if (input == 5) {
			//lots of issues for some reason getting this to work
			char title[25];
			fseek(stdin, 0, SEEK_END);
			printf("Enter a song title: ");
			fgets(title, 25, stdin);
			strtok(title, "\n");
			deleteRecord(&list, title);
		}
		//edit command
		else if (input == 6) {
			printf("Enter an artists name (note it is case sensitive): ");
			char name[20];
			scanf(" %s", name);
			edit(&list, name);
		}
		//sort command
		else if (input == 7) {
			printf("Enter an attribute to sort by:\n1.Artist\n2.Album Title\n3.Rating\n4.Times played (largest-smallest)\n");
			int input = 0;
			scanf("%d", &input);
			//input validation loop
			while (input < 0 && input>4) {
				printf("Incorrect attribute try again: ");
				scanf("%d", &input);
			}
			system("cls");
			sortList(&list, input);
			display(list, NULL);
		}
		//rate command
		else if (input == 8)
			rate(&list);
		//play command
		else if (input == 9)
			play(list);
		//shuffle command
		else if (input == 10)
			shuffle(list, getSize(list), generatePositions(getSize(list)));
		//exit command
		else if (input == 11) {
			store(infile, list);
			break;
		}
		//clearing the screen and printing the options after every run
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
			//end case if the end of the file is reached where there is no line
			if (*line == '\0'||*line=='\n')
				break;
			//case if there is quotation marks around the artists name
			if (*line == '\"') {
				//ignoring the first quotation mark, replacing the end w/ a null char
				strcpy(temp.artist, strtok(line + 1, "\""));
			}
			//normal case
			else
				strcpy(temp.artist, strtok(line, ","));
			//copies all the data from the line into temp
			strcpy(temp.album, strtok(NULL, ","));
			strcpy(temp.title, strtok(NULL, ","));
			strcpy(temp.genre, strtok(NULL, ","));
			temp.duration.mins = atoi(strtok(NULL, ":"));
			temp.duration.secs = atoi(strtok(NULL, ","));
			temp.timesPlayed = atoi(strtok(NULL, ","));
			temp.rating = atoi(strtok(NULL, "\n"));
			//inserts the data into the front of the list
			insertAtFront(list, temp);
		}
		success = 1;
	}
	return success;
}
Node *makeNode(Record data) {
	//allocating memory for the node
	Node *temp = (Node*)malloc(sizeof(Node));
	//setting all the links + the data
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
		//setting links
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
		//if artist is NULL display all songs
		if (artist == NULL || strcmp(temp.artist, artist) == 0) {
			displayRecord(temp);
		}
		list = list->next;
	}
}
int store(FILE *file, Node *list) {
	//assumes the *file is not opened in write mode
	file = fopen("musicPlayList.csv", "w");
	if (file != NULL) {
		//moving through the list until the end (to print from the end of the list to the beginning (same order that was read in)
		while (list->next != NULL)
			list = list->next;
		Record temp = list->song;
		//adding the line to the file (first case) 
		fprintf(file, "\"%s\",%s,%s,%s,%d:%d,%d,%d", temp.artist, temp.album, temp.title, temp.genre, temp.duration.mins, temp.duration.secs, temp.timesPlayed, temp.rating);
		list = list->prev;
		while (list != NULL) {
			//regular case for adding a line to the file (avoids adding an extra line to the file)
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
	//indices is the index that the songs must be edited in the list (for multiple artists + general case)
	int count = 0, indices[100], index=0;
	Node *temp = *list;
	while (temp->next != NULL) {
		//looks for multiple artists
		if (strcmp(temp->song.artist, artist) == 0) {
			//only have to advance forward x positions from the initial position
			if (count > 0)
				indices[count] = index-indices[0];
			//storing the initial index for the list
			else
				indices[count] = index;
			count++;
		}
		temp = temp->next;
		index++;
	}
	//last case
	if (strcmp(temp->song.artist, artist) == 0) {
		if (count > 0)
			indices[count] = index - indices[0];
		else
			indices[count] = index;
		count++;
	}
	//readvancing back through the list
	while (temp->prev != NULL)
		temp = temp->prev;
	if (count == 0) {
		printf("No artists found by that name!\n");
		return;
	}
	else if (count == 1) {
		//advancing through the list n times until the index with the matching artist is met
		for (int i = 0; i < indices[0]; i++) {
			temp = temp->next;
		}
		int input = 0;
		while (input != 8) {
			//allows the user to edit the record as many times as they want until they exit
			printf("Edit Record:\n1.Artist\n2.Album\n3.Song\n4.Genre\n5.Song Length\n6.Number of times played\n7.Rating\n8.Done\nEnter your choice: ");
			scanf("%d", &input);
			if(input!=8)
				editRecord(&(temp->song), input);
		}
	}
	//case for multiple artists
	else {
		//displaying all the songs by that artist
		printf("Enter the number of which song to edit:\n");
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < indices[i]; j++)
				temp = temp->next;
			printf("%d. ", i+1);
			displayRecord(temp->song);
		}
		//getting the song to edit
		int input = 0;
		scanf("%d", &input);
		while (input <= 0 || input > count) {
			printf("Invalid input try again: ");
			scanf("%d", &input);
		}
		//readvancing back to the beginning of the list (again)
		while (temp->prev != NULL)
			temp = temp->prev;
		if (input == 1) {
			//special case if the input=1(same as single case)
			for (int i = 0; i < indices[input-1]; i++) {
				temp = temp->next;
			}
		}
		else {
			//general case
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
	//very simple function - just allows for the user to edit one specific aspect of a record (also validates all the input for times played and rating)
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
	//uses a temp variable just to not advance back through the list
	Node *temp = list;
	int count=1, index = 0;
	//displays all the songs to be selected by the user
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
	//displays all the songs up until count (end of the list) starting from the index selected by the user
	for (int i = index; i < count; i++) {
		displayRecord(temp->song);
		system("pause");
		system("cls");
		temp = temp->next;
	}
}
void rate(Node **list) {
	Node *temp = *list;
	//count keeps track of the size of the list
	int count = 0, input = 0;
	while (input != count + 1) {
		count = 0;
		//displays all the records and allows the user to select one to rate (including an exit)
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
		//advancing through the list backwards until the index is reached of the song
		if (input != count + 1) {
			for (int i = count; i > input; i--)
				temp = temp->prev;
			//just reused editrecord and 7 (for rating)
			editRecord(&(temp->song), 7);
			//going back to the beginning of the list
			while (temp->prev != NULL)
				temp = temp->prev;
		}
	}
}
int insert(Node **list) {
	Record r;
	//getting all the info for the record (validation for times played and rating happens at insertAtFront)
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
			//case if the node is at the front
			if (temp->prev == NULL) {
				*list = temp->next;
				free(temp);
				return 1;
			}
			//case if the node is at the end
			else if (temp->next == NULL) {
				temp->prev->next = NULL;
				free(temp);
				return 1;
			}
			//general case
			else {
				//setting the links
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
	//counts the size of the list (sizeof wasnt working)
	for (; list != NULL; size++)
		list = list->next;
	return size;
}
void shuffle(Node *list, int size, int *order) {
	system("cls");
	//curP is the current position of the index
	int curP = *order, index = 0;
	while (index < size) {
		//fancy math to essentially get the current position in the list based on the order 
		if (index != 0)
			curP = curP - *(order + index - 1);
		if (curP > 0) {
			//advancing through the list forwards if the current position is >0 (the list needs to be advanced curP times)
			for (int i = 0; i < curP; i++)
				list = list->next;
		}
		else {
			//advancing throught the list backwards
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
	//filling the array with values from 0 to size-1
	for (int i = 0; i < size; i++) {
		*(vals + i) = i;
	}
	//shuffling the values around using random indices
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
	//selection sort algorithm
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
				//special case (sorting largest to smallest instead of smallest to largest)
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
	//only need to swap the data around - don't need to swap the links
	Record temp = (*list1)->song;
	(*list1)->song = (*list2)->song;
	(*list2)->song = temp;
}