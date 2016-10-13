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

const int maxn = 1 << 24;

intrusive_list load(char* filename, bool b){
	FILE* inf = fopen(filename, b ? "rt" : "rb");
	intrusive_list lst;
	init_list(&lst);
	int* vt = (int*) malloc(sizeof(int));
	int sz = 1;
	int n = 0;
	int x[2] = {0, 0};
	while (!feof(inf)){
		if (b)
			fscanf(inf, "%d %d ", &x[0], &x[1]);
		else{
			if (fread(&x[0], 3, 1, inf) != 1) break;
			fread(&x[1], 3, 1, inf);
			for (int z = 0; z < 2; z++)
				if (x[z] > (maxn >> 1)) x[z] = - ((x[z] - 1) ^ (maxn - 1));
		}
		for (int z = 0; z < 2; z++){
			if (n == sz){
				int *b = (int*) malloc(sizeof(int) * 2 * sz);
				for (int i = 0; i < sz; i++)
					b[i] = vt[i];
				sz *= 2;
				free(vt);
				vt = b;
			}
			vt[n++] = x[z];
		}
	}
	while(n > 0){
		n -= 2;
		add_position(&lst, vt[n], vt[n + 1]);
	}
	free(vt);
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
		int x = (item -> x);
		int y =(item -> y);
		if (x < 0) x = 1 + ((-x) ^ (maxn - 1));
		if (y < 0) y = 1 + ((-y) ^ (maxn - 1));
		fwrite(&x, 3, 1, ouf);
		fwrite(&y, 3, 1, ouf);
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
	ct[0]++;
}

void apply(intrusive_list *lst, void (*op)(position_node*, void*), void* par) {
    //if (lst->head == NULL) printf("<empty line>");
    for (intrusive_node* cur = lst->head; cur != NULL; cur = cur->next){
        position_node *item = container_of(cur, position_node, node);
        op(item, par);
    }
}
