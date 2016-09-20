#include "stddef.h"

char * strcpy(char * destination, const char * source){
    for (char* d = destination; *source;){
        *d++ = *source++;
        *d = 0;
    }
    return destination;
}

char * strcat(char * destination, const char * source){
    char* a = destination;
    const char* b = source;
    for (; *a != 0; a++);
    for (; *b != 0; a++, b++, *a = 0){
        *a = *b;
    }
    return destination;    
}

int strcmp(const char * str1, const char * str2){
    const char* a = str1;
    const char* b = str2;
    for (; *a != 0 || *b != 0; a++, b++){
        if (*a < *b) return -1;
        if (*a > *b) return 1;
    }
    return 0;
}

size_t strlen(const char * str){
    const char* c = str;
    for (; *c != 0; c++);
    return c - str;
}