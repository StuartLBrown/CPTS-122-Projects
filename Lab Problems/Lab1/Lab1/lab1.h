#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//task 2a
void strreverse(char *str, int size);

//task 2b
char *myStrTok(char *str, const char *delimiter);
int notContainedInDelimm(char *str, const char *delimiter);
int containedInDelimm(char *str, const char *delimiter);

//task 2c
char *sortTwoStrings(char *str1, char *str2);
void sortString(char *str, int length);
char *mergeString(char *str1, int l1, char *str2, int l2);
int getLength(char *str);