#pragma once

#include <stdbool.h>

typedef struct tree_node {
    char data;
    struct treeNode* left;
    struct treeNode* right;
} tree_node_t;

void insert(tree_node_t** tree, char data);

bool contains(tree_node_t* tree, char data);

int count_nodes(tree_node_t* tree);

int get_height(tree_node_t* tree);

void destroy(tree_node_t* tree);