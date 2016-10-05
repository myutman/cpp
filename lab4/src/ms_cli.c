#include <stdio.h>
#include "../include/util.h"

int main(int argc, char* argv[]){
	int i;
	if (argv[1][0] == 'i'){
		int *a = (int*)malloc((argc - 1) * sizeof(int));
		for (i = 2; i < argc; i++){
			a[i - 2] = atoi(argv[i]);
		}
		mergesort(a, argc - 2, sizeof(int), intcmp);
		for (i = 2; i < argc; i++){
			printf("%d ", a[i - 2]);
		}
		free(a);
	}
	else if(argv[1][0] == 's'){
		char **a = (char**)malloc((argc - 1) * sizeof(char*));
		for (i = 2; i < argc; i++){
			a[i - 2] = malloc(strlen(argv[i]) + 1);
			strcpy(a[i - 2], argv[i]);
		}
		//printf("hello\n");
		mergesort(a, argc - 2, sizeof(char*), strcmp);
		for (i = 2; i < argc; i++){
			printf("%s ", a[i - 2]);
		}
		free(a);
	}
	else{
		char *a = (char*)malloc((argc - 2) * sizeof(char));
		for (i = 2; i < argc; i++){
			a[i - 2] = argv[i][0];
		}
		mergesort(a, argc - 2, sizeof(char), charcmp);
		for (i = 2; i < argc; i++){
			printf("%c ", a[i - 2]);
		}
		free(a);
	}
	printf("\n");
	return 0;
}
