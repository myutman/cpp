#include "../include/util.h"
#include <stdio.h>

char * strcpy(char * destination, const char * source){
    char* d;
    for (d = destination; *source;){
        *d++ = *source++;  
    }
    *d = 0;
    return destination;
}

size_t strlen(const char * str){
    const char* c = str;
    for (; *c != 0; c++);
    return c - str;
}

void copy(char *dest, char *src, size_t size){
	int i;
	//printf("util.c:");
	for (i = 0; i < size; i++){
		dest[i] = src[i];
		//printf(" %d", dest[i]);
	}
	//printf("%d\n"); 
}

int strcmp(char** a, char** b){
	char *str1 = *a;
	char *str2 = *b;
	//printf("%s %s %c %c", str1, str2, *str1, *str2); 
	while (*str1 && *str1 == *str2) str1++, str2++;
	return (int)(*str1) - (int)(*str2);
}

int intcmp(int* a, int* b){
	return (*a) - (*b);
}

int charcmp(char* a, char* b){
	return (int)(*a) - (int)(*b);
}
