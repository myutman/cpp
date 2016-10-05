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

int strcmp(const void* a, const void* b){
	char **s1 = (char**)a;
	char **s2 = (char**)b;
	char *str1 = *s1;
	char *str2 = *s2;
	//printf("%s %s %c %c", str1, str2, *str1, *str2); 
	while (*str1 && *str1 == *str2) str1++, str2++;
	return ((int)(*str1) - (int)(*str2));
}

int intcmp(const void* a, const void* b){
	return (*((int*)a) - *((int*)b));
}

int charcmp(const void* a, const void* b){
	return ((int)*((char*)a) - (int)*((char*)b));
}
