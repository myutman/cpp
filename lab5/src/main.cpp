#include <stdio.h>
#include <stdlib.h>
#include "../include/clist.h"
#include "../include/intrusive.h"
#include "../include/str.h"

void print(intrusive_list *lst, char* format){
	apply(lst, print_node, (void*)format);
}

int count(intrusive_list *lst){
	int ct = 0;
	apply(lst, count_node, (void*)&ct);
	return ct;
}

int main(int argc, char* argv[]){
	char* arg[5];
	for (int i = 0; i < argc; i++){
		arg[i] = (char*) malloc(strlen(argv[i]));
		strcpy(arg[i], argv[i]);
	}
	bool b = strcmp(arg[1], "loadtext") == 0;
	intrusive_list lst = load(arg[2], b);
	if (strcmp(arg[3], "savetext") == 0){
		save(&lst, arg[4], 1);
	}
	else if (strcmp(arg[3], "savebin") == 0){
		save(&lst, arg[4], 0);
	}
	else if (strcmp(arg[3], "print") == 0){
		print(&lst, arg[4]);	
	}
	else if(strcmp(arg[3], "count") == 0){
		printf("%d\n", count(&lst));
	}
	remove_all_positions(&lst);
	for (int i = 0; i < argc; i++){
		free(arg[i]);
	}
	return 0;
}
