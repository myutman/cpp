#pragma once
#include <stddef.h>

char* strcpy(char*, const char*);
size_t strlen(const char*);
int mergesort (void* base, size_t num, size_t size, int (*cmp(const void*, const void*)));
int strcmp(char**, char**);
int intcmp(int*, int*);
int charcmp(char*, char*);
void copy(char *dest, char *src, size_t size);

