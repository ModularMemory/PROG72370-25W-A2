#pragma once

#include <stdbool.h>

typedef struct tree_node {
    char data;
    struct treeNode* left;
    struct treeNode* right;
} tree_node_t;

void insert(tree_node_t** tree, char data);

bool contains(tree_node_t* tree, char data);

int countNodes(tree_node_t* tree);

int getHeight(tree_node_t* tree);