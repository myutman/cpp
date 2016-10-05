#pragma once
#include <stddef.h>
#include <stdlib.h>

typedef int (*cmp_f(const void* a, const void* b));

char* strcpy(char*, const char*);
size_t strlen(const char*);
int mergesort (void* base, size_t num, size_t size, int (*cmp)(const void*, const void*));
int strcmp(const void*, const void*);
int intcmp(const void*, const void*);
int charcmp(const void*, const void*);
void copy(char *dest, char *src, size_t size);

