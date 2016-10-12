#ifndef _INTRUSIVE_H_
#define _INTRUSIVE_H_
#include "clist.h"

intrusive_list load(char* filename, bool b);
void save(intrusive_list *lst, char* filename, bool b);
void add_position(intrusive_list *lst, int x, int y);
void print_node(position_node* item, void* par);
void count_node(position_node* item, void* par);
void apply(intrusive_list *lst, void (*op)(position_node*, void*), void* par);
void remove_all_positions(intrusive_list *lst);
#endif


