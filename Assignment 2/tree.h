#pragma once

typedef struct tree_node {
    int data;
    struct treeNode* left;
    struct treeNode* right;
} tree_node_t;

void insert(tree_node_t* tree, int data);

void search(tree_node_t* tree, int data);

void countNodes(tree_node_t* tree);

void checkHeight(tree_node_t* tree);