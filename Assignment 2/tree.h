#pragma once

#include <stdbool.h>

typedef struct tree_node {
    char data;
    struct treeNode* left;
    struct treeNode* right;
} tree_node_t;

typedef struct b_tree {
    tree_node_t* head;
} *BTree;

BTree create_tree(void);

void insert(BTree tree, char data);

bool contains(BTree tree, char data);

int count_nodes(BTree tree);

int get_height(BTree tree);

void destroy_tree(BTree tree);