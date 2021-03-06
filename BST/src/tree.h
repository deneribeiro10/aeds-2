#ifndef __TREE_H__
#define __TREE_H__

#include <stdlib.h>
#include "item.h"

typedef struct tree_t * TreePtr;

void tree_init(TreePtr *tree);
void tree_insert_item(TreePtr *tree, Item item);
void tree_remove_item(TreePtr *tree, Item item);

TreePtr tree_find_item(TreePtr tree, Item item);
int tree_get_heigh(TreePtr tree);
Item tree_get_item(TreePtr tree);
TreePtr tree_get_left_node(TreePtr tree);
TreePtr tree_get_right_node(TreePtr tree);

#endif
