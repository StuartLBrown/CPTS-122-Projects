#ifndef DMM_H
#define DMM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef struct {
	int mins;
	int secs;
}Duration;
typedef struct {
	char artist[20];
	char album[25];
	char title[25];
	char genre[15];
	Duration duration;
	int timesPlayed;
	int rating;
}Record;
typedef struct node {
	struct node *prev;
	struct node *next;
	Record song;
}Node;
//done
void menu(FILE *infile);

//done
Node *makeNode(Record data);

//done
int load(FILE *infile, Node **list);

//precondition: file doesn't have to be in write mode beforehand, data will be overwritten anyway
//done
int store(FILE *file, Node *list);

//done
void display(Node *list,char *artist);
//done
void edit(Node **list, char *artist);

void rate(Node **list);
//done
void play(Node *list);

//done
int insertAtFront(Node **list, Record data);

//done
int insert(Node **list);

//done
int deleteRecord(Node **list, char *title);

void displayRecord(Record r);

//done
void editRecord(Record *r, int attribute);

int getSize(Node *list);

//1 is artist, 2 is album title, 3 is rating, 4 is times played (largest-smallest) - uses selection sort
void sortList(Node **list, int attribute);

//pointers are to the indexes that need to be swapped
void swap(Node **list1, Node **list2);

//precondition:
//size = size of order
void shuffle(Node *list, int size, int *order);

int *generatePositions(int size);

#endif // !1
