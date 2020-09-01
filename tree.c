#include "tree.h"

/* Model Structure */
struct tree_t {
    Item info;
    TreePtr left, right;
};

/* Private Functions Declaration */
static TreePtr tree_new(Item info, TreePtr left, TreePtr right);
static TreePtr * predecessor(TreePtr *tree);

/* Private Functions Implementation */ 
static TreePtr tree_new(Item info, TreePtr left, TreePtr right) {
    TreePtr node = (TreePtr) malloc(sizeof *node);
    node->info = info;
    node->left = left;
    node->right = right;
    return node;
};

static TreePtr * predecessor(TreePtr *tree) {
    TreePtr *left = &(*tree)->left;
    if(*left == NULL) return NULL;
    while((*left)->right) {
        left = &(*left)->right;
    }
    return left;
}

/* Public Functions Implementation */
void tree_init(TreePtr *tree) {
    *tree = NULL;
}

void tree_insert_item(TreePtr *tree, Item item) {
    TreePtr *root = tree;
    while(*root) {
        if(item_cmp(item, (*root)->info) <= 0) 
            root = &(*root)->left;
        else 
            root = &(*root)->right;
    }
    *root = tree_new(item, NULL, NULL);
}

void tree_remove_item(TreePtr *tree, Item item) {
    if(*tree == NULL) return;
    TreePtr *root = tree;
    while((*root)->info != item) {
        if(item_cmp(item, (*root)->info) <= 0) 
            root = &(*root)->left;
        else
            root = &(*root)->right;
        if(*root == NULL) return;
    }
    TreePtr *pr = predecessor(root);
    TreePtr rem;
    if(pr) {
        rem = *pr;
        (*tree)->info = (*pr)->info;
        (*pr) = NULL;
    } else {
        rem = *tree;
        *tree = (*tree)->right;
    }
    free(rem);
}

Item tree_get_item(TreePtr tree) {
    return tree->info;
}

TreePtr tree_get_left_node(TreePtr tree) {
    return tree->left;
}

TreePtr tree_get_right_node(TreePtr tree) {
    return tree->right;
}
