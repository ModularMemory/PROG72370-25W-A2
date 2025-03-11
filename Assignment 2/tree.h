#pragma once

#include <stdbool.h>

typedef struct tree_node {
    char data;
    struct tree_node* left;
    struct tree_node* right;
} tree_node_t;

typedef struct b_tree {
    tree_node_t* head;
} *BTree;

/// <summary>
/// Creates an empty BTree
/// </summary
BTree create_tree(void);

/// <summary>
/// Inserts a character into a BTree
/// </summary>
void insert(BTree tree, char data);

/// <summary>
/// Checks if a BTree contains a given character
/// </summary>
bool contains(BTree tree, char data);

/// <summary>
/// Counts the number of nodes in a BTree
/// </summary>
int count_nodes(BTree tree);

/// <summary>
/// Computes the height of a BTree
/// </summary>
int get_height(BTree tree);

/// <summary>
/// Destroys a BTree
/// </summary>
void destroy_tree(BTree tree);