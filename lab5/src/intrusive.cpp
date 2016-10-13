#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/clist.h"

void remove_all_positions(intrusive_list *lst) {
    for (intrusive_node* cur = lst->head; cur != NULL;){
        intrusive_node *old = cur;
        cur = cur->next;
        remove_node(lst, old);
    }
}

void add_position(intrusive_list *lst, int x, int y) {
    position_node *nd = (position_node*) malloc(sizeof(position_node));
    nd->x = x;
    nd->y = y;
    nd->node.next = nd->node.prev = NULL;
    add_node(lst, &nd->node);
}

intrusive_list load(char* filename, bool b){
	FILE* inf = fopen(filename, b ? "rt" : "rb");
	intrusive_list lst;
	init_list(&lst);
	if (b){
		int x = 0, y = 0;
		while (!feof(inf)){
			fscanf(inf, "%d %d ", &x, &y);
			add_position(&lst, x, y);
		}
	}
	else{
		int x = 0, y = 0;
		while (fread(&x, 3, 1, inf) == 1){
			fread(&y, 3, 1, inf);
			add_position(&lst, x, y);
		}
	}
	fclose(inf);
	return lst;
}

void save(intrusive_list *lst, char* filename, bool b){
    FILE* ouf = fopen(filename, b ? "wt" : "wb");
    for (intrusive_node* cur = lst->head; cur != NULL; cur = cur->next){
        position_node *item = container_of(cur, position_node, node);
        if (b)
		fprintf(ouf, "%d %d\n", item -> x, item -> y);
	else{
		fwrite(&(item -> x), 3, 1, ouf);
		fwrite(&(item -> y), 3, 1, ouf);
		void *k = &(item->x);
		for (int i = 0; i < 3; i++){
			int z = *((char*)k + i);
			printf("%d ", z);
		}
		printf("\n");
	}
    }
    fclose(ouf);
}

void print_node(position_node* item, void* par){
	char* format = (char*) par;
	printf(format, item->x, item->y);
}

void count_node(position_node* item, void* par){
	int* ct = (int*) par;
	*ct++;
}

void apply(intrusive_list *lst, void (*op)(position_node*, void*), void* par) {
    //if (lst->head == NULL) printf("<empty line>");
    for (intrusive_node* cur = lst->head; cur != NULL; cur = cur->next){
        position_node *item = container_of(cur, position_node, node);
        op(item, par);
    }
}
