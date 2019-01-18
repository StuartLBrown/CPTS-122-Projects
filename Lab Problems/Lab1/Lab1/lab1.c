#include "lab1.h"
//task 2a
void strreverse(char *str, int size) {
	if (size > 1) {
		char temp = *str;
		*str = *(str + size - 1);
		*(str + size - 1) = temp;
		strreverse(str + 1, size - 2);
	}
}

//task 2b
char *myStrTok(char *str, const char *delimiter) {
	//token to keep track of the start of the next string
	static char *pToken;
	//edge cases
	if (delimiter == NULL)
		return NULL;
	//first case
	if (str != NULL) {
		//index is the beginning of the token, end is the end of the token, found is a way to keep track if the dellim is contained inside the string
		int index = 0, found=0, end=0;
		//looping until the null char is reached
		while (*(str + index) != '\0') {
			//if the character at index is != to dellim then that is the start of the token
			if (notContainedInDelimm(*(str + index), delimiter)) {
				//looping until the null char is reached
				while (*(str + end) != '\0') {
					//looking until the end of the token is found
					found = containedInDelimm(*(str + end), delimiter);
					if (found != 0) 
						break;
					end++;
				}
				break;
			}
			index++;
		}
		//making the end of the token a null char
		*(str + end) = '\0';
		//copying the end of the token into pToken
		pToken = (str + end + 1);
		//if there is not delimmiter found in the string, just return the whole string
		if (found == 0)
			return str;
	}
	else {
		//if there is nothing left in the string
		if (pToken == NULL)
			return NULL;
		//same thing as above, just replacing str with pToken and vice versa
		//index is the beginning of the token, end is the end of the token
		int index = 0, found = 0, end = 0;
		while (*(pToken + index) != '\0') {
			if (notContainedInDelimm(*(pToken + index), delimiter)) {
				while (*(pToken + end) != '\0') {
					found = containedInDelimm(*(pToken + end), delimiter);
					if (found != 0) 
						break;
					end++;
				}
				break;
			}
			index++;
		}
		//special case if the end of the string is reached, set pToken to null and return the rest of the string 
		if (found == 0) {
			str = pToken;
			pToken = NULL;
			return str;
		}
		*(pToken + end) = '\0';
		str = pToken;
		pToken = (str + end + 1);
	}
	return str;
}
//helper function to determine the start of the token (1 if it is the start, 0 if not)
int notContainedInDelimm(char str, const char *delimiter) {
	int index = 0;
	while (*(delimiter + index) != '\0') {
		if (str != *(delimiter + index))
			return 1;
		index++;
	}
	return 0;
}
//similar to notContainedInDelimm except it looks until they are equal
int containedInDelimm(char str, const char *delimiter) {
	int index = 0;
	while (*(delimiter + index) != '\0') {
		if (str == *(delimiter + index))
			return 1;
		index++;
	}
	return 0;
}

char *sortTwoStrings(char *str1, char *str2) {
	int l1 = getLength(str1), l2 = getLength(str2);
	sortString(str1, l1);
	sortString(str2, l2);
	return mergeString(str1, l1, str2, l2);
}

//selection sort
void sortString(char *str, int length) {
	for (int i = 0; i < length - 1; i++) {
		int minIndex=i;
		for (int j = i + 1; j < length; j++) {
			if (*(str + j) < *(str + minIndex))
				minIndex = j;
		}
		if (minIndex != i) {
			char temp = *(str + minIndex);
			*(str + minIndex) = *(str + i);
			*(str + i) = temp;
		}
	}
}
//gets the length of a string
int getLength(char *str) {
	return (sizeof(str) / sizeof(char)-1);
}
char *mergeString(char *str1, int l1, char *str2, int l2) {
	int i1=0, i2=0;
	char *sorted = (char*)malloc(sizeof(char)), *temp;
	for (int i = 0; i < (l1 + l2); i++) {
		if (i1<l1&&*(str1 + i1) < *(str2 + i2)) {
			*(sorted+i) = *(str1 + i1);
			i1++;
		}
		else{
			if (i2 < l2) {
				*(sorted+i) = *(str2 + i2);
				i2++;
			}
		}
	}
	sorted = (char*)realloc(sorted, sizeof(char));
	*(sorted + l1 + l2) = '\0';
	return sorted;
}