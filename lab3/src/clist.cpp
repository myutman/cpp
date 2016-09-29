#include "../include/clist.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void init_list(intrusive_list *lst){
    lst->head = NULL;
}

void add_node(intrusive_list *lst, intrusive_node *nd){
    if (lst->head != NULL)
        lst->head->prev = nd;
    nd->next = lst->head;
    lst->head = nd;
}

void remove_node(intrusive_list *lst, intrusive_node *nd){
    if (nd == lst->head)
        lst->head = nd->next;
    else
        nd->prev->next = nd->next;
    if (nd->next != NULL)
        nd->next->prev = nd->prev;
    position_node *seg = container_of(nd, position_node, node);
    free(seg);
}

int get_length(intrusive_list *lst){
    int len = 0;
    for (intrusive_node* it = lst->head; it != NULL; it = it->next, len++);
    return len;
}