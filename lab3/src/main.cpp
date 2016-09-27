#define container_of(ptr, type, member) (type*)((char*)(ptr) - offsetof(type, member))
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/clist.h"

struct position_node {
	int x, y;
	struct intrusive_node node;
};

void remove_position(intrusive_list *lst, int x, int y) { // removes all (x, y) pairs
    for (intrusive_node* cur = lst->head; cur != NULL; cur = cur->next){
        position_node *item = container_of(cur, struct position_node, node);
        if (item->x == x && item->y == y){
            remove_node(lst, cur);
        }
    }
}

void add_position(intrusive_list *lst, int x, int y) {
    position_node *nd = (position_node*) malloc(sizeof(position_node));
    nd->x = x;
    nd->y = y;
    nd->node.next = nd->node.prev = NULL;
    add_node(lst, &nd->node);
}

void show_all_positions(intrusive_list *lst) {
    //if (lst->head == NULL) printf("<empty line>");
    for (intrusive_node* cur = lst->head; cur != NULL; cur = cur->next){
   		position_node *item = container_of(cur, position_node, node);
        printf("(%d %d) ", item->x, item->y);
    }
    printf("\n");
}

void remove_all_positions(intrusive_list *lst) {
    for (intrusive_node* cur = lst->head; cur != NULL; cur = cur->next)
        remove_node(lst, cur);
}

int main() {
    /* usage
       intrusive_list_t l;
       init_list(&l);
       add_positon(&l, 10, 10);
       add_positon(&l, 20, 20);
       show_all_positions(&l);
       return 0;
    */
    char s[10];
    intrusive_list *lst = (intrusive_list*) malloc(sizeof(intrusive_list));
    init_list(lst);
    while (scanf("%s", s) == 1){
        if (strcmp(s, "add") == 0){
            int x, y;
            scanf("%d %d", &x, &y);
            add_position(lst, x, y);
        }
        else if (strcmp(s, "rm") == 0){
            int x, y;
            scanf("%d %d", &x, &y);
            remove_position(lst, x, y);
        }
        else if (strcmp(s, "rma") == 0){
            remove_all_positions(lst);
        }
        else if (strcmp(s, "len") == 0){
            printf("%d\n", get_length(lst));
        }
        else if(strcmp(s, "print") == 0){
            show_all_positions(lst);
        }
        else if(strcmp(s, "exit") == 0){
            return 0;            
        }
        else{
            printf("Unknown command\n");
        }
        scanf("\n");
    }
    return 0;
}