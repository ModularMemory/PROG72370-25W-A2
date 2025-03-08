#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

static tree_node_t* create_node(char data) {
    tree_node_t* node = (tree_node_t*)malloc(sizeof(tree_node_t));
    if (!node) {
        fprintf(stderr, "Error: Failed to allocate new node.\n");
        exit(EXIT_FAILURE);
    }

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

static tree_node_t* insert_impl(tree_node_t* tree, char data) {
    if (!tree) {
        return create_node(data);
    }

    int a = data - tree->data;
    if (a < 0) {
        tree->left = insert_impl(tree->left, data);
    }
    else {
        tree->right = insert_impl(tree->right, data);
    }

    return tree;
}

void insert(tree_node_t** tree, char data) {
    *tree = insert_impl(tree, data);
}

bool contains(tree_node_t* tree, char data) {
    if (!tree) {
        return false;
    }

    int a = data - tree->data;
    if (a == 0) {
        return true;
    }

    if (a < 0) {
        return contains(tree->left, data);
    }

    return contains(tree->right, data);
}

int count_nodes(tree_node_t* tree) {
    if (!tree) {
        return 0;
    }

    return count_nodes(tree->left) + count_nodes(tree->right) + 1;
}

int get_height(tree_node_t* tree) {
    if (!tree) {
        return -1;
    }

    int left = get_height(tree->left);
    int right = get_height(tree->right);

    if (left > right) {
        return 1 + left;
    }

    return 1 + right;
}

void destroy(tree_node_t* tree) {
    if (!tree) {
        return;
    }

    destroy(tree->left);
    destroy(tree->right);

    free(tree);
}