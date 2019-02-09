#ifndef DMM_H
#define DMM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//used to store the duration of the song
typedef struct {
	int mins;
	int secs;
}Duration;

//used to store the whole record
typedef struct {
	char artist[20];
	char album[25];
	char title[25];
	char genre[15];
	Duration duration;
	int timesPlayed;
	int rating;
}Record;

//struct for the double linked list
typedef struct node {
	struct node *prev;
	struct node *next;
	Record song;
}Node;

//prints and handles the whole menu system, including initializing the double linked list
//preconditon: *infile must not be NULL
void menu(FILE *infile);

//Allocates memory for a new node
//precondition: data must not be NULL
//postcondition Node * will not be NULL
//returns the newly allocated Node *
Node *makeNode(Record data);

//loads the contents of the file into the list
//precondition: *infile must not be NULL and **list must be initialized beforehand (either with NULL or other data)
//return value: if the contents of file were succesfully loaded into the list return 1 else return 0
int load(FILE *infile, Node **list);

//stores the contents of the list into the file
//precondition: *list must not be NULL and *file must not be NULL
//return value: if the contents were succesfully stored into the file return 1 else return 0
int store(FILE *file, Node *list);

//displays all songs by the artist in the list (if artist is NULL display all songs)
//precondition *list must not be NULL
void display(Node *list,char *artist);

//edits a single record in the list by that artist (edits all parameters of the record)
//if there are multiple records by the same artist in the list only one song can be edited (all will be displayed)
//precondition **list must not be NULL and artist must not be NULL
void edit(Node **list, char *artist);

//allows the user to rate all songs (1-5)
//precondition: **list must not be NULL
void rate(Node **list);

//"plays" all the songs (displays all the info to the screen and pauses then clears)
void play(Node *list);

//inserts a node at the front with the data
//precondition: data must not be NULL
//return value: 1 if succesfull 0 if not
int insertAtFront(Node **list, Record data);

//allows the user to insert a new record into the front of the list
//return value: same as insertAtFront
int insert(Node **list);

//deletes the record in the list that matches the title
//precondition: title must not be equal to NULL
//return value: 1 if succesfull (found record to delete that matches the title)
int deleteRecord(Node **list, char *title);

//displays a single record to the screen
//precondition: r must not be NULL
void displayRecord(Record r);

//allows the user to edit a single record based on a specific attribute (same order as in file)
//precondtion: *r must not be NULL and attribute must be between 1 and 7
void editRecord(Record *r, int attribute);

//gets the size of the list
//return value: the size of the list (number of nodes)
int getSize(Node *list);

//sorts the list using selection sort based on the attribute 1 is artist, 2 is album, 3 is rating, and 4 is times played (largest-smallest)
//precondition: **list must not be NULL and attribute must be between 1 and 4
void sortList(Node **list, int attribute);

//swaps the data of the two nodes (all that is needed)
//precondition: both **list1 and **list2 must not be NULL
void swap(Node **list1, Node **list2);

//shuffles a copy of the list to be played
//precondition: *list must not be NULL, size must be the size of the list, and *order is an array of integers showing the order that it is to be played (must also have the same size as size) - get this array from generatepositions
void shuffle(Node *list, int size, int *order);

//generates a random list of size size o integers from 0 to size-1
//precondition size must be the size of the list that needs to be shuffled
//return value: the random array of integers
int *generatePositions(int size);

#endif // !1
