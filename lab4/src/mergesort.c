#include "../include/util.h"
#include <stdio.h>

int mergesort (void* base, size_t num, size_t size, int (*cmp(const void*, const void*))){
	if (num == 1)
		return 0;
	int n1 = num / 2;
	mergesort(base, n1, size, cmp);
	mergesort(base + n1 * size, num - n1, size, cmp);
	char *an = malloc(num * size);
	int k = 0;
	int i = 0;
	int j = n1;
	while (i < n1 || j < num){
		//printf("mergesort.c: %d %d", i == n1 ? -1 : *((int*) (base + i * size)), j == num ? -1 : *((int*) (base + j * size)));
		//printf("%s %s", *((char **)(base + i * size)), *((char **)(base + j * size)));
		if (j == num || ((i < n1) && ((int)cmp(base + i * size, base + j * size) < 0))){
			//printf("hello\n");
			copy(&an[k], &base[(i++) * size], size);
			k += size;
		}
		else{
			//printf("hello\n");
			copy(&an[k], &base[(j++) * size], size);
			k += size;
		}
		//printf("hello\n");
		//printf(" %d\n", *((int*) (an + k - size)));
	}
	for (i = 0; i < num * size; i += size)
		copy(&base[i], &an[i], size);
	free(an);
}
