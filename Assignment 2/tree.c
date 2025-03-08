#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

BTree create_tree(void) {
    BTree tree = (BTree)malloc(sizeof(struct b_tree));
    if (!tree) {
        fprintf(stderr, "Error: Failed to allocate new tree.\n");
        exit(EXIT_FAILURE);
    }

    tree->head = NULL;

    return tree;
}

static tree_node_t* create_node(char data, tree_node_t* left, tree_node_t* right) {
    tree_node_t* node = (tree_node_t*)malloc(sizeof(tree_node_t));
    if (!node) {
        fprintf(stderr, "Error: Failed to allocate new node.\n");
        exit(EXIT_FAILURE);
    }

    node->data = data;
    node->left = left;
    node->right = right;

    return node;
}

static tree_node_t* insert_impl(tree_node_t* node, char data) {
    if (!node) {
        return create_node(data, NULL, NULL);
    }

    int order = data - node->data;
    if (order < 0) {
        node->left = insert_impl(node->left, data);
    }
    else {
        node->right = insert_impl(node->right, data);
    }

    return node;
}

void insert(BTree tree, char data) {
    tree->head = insert_impl(tree->head, data);
}

static bool contains_impl(tree_node_t* node, char data) {
    if (!node) {
        return false;
    }

    int order = data - node->data;
    if (order == 0) {
        return true;
    }

    if (order < 0) {
        return contains_impl(node->left, data);
    }

    return contains_impl(node->right, data);
}

bool contains(BTree tree, char data) {
    return contains_impl(tree->head, data);
}

static int count_nodes_impl(tree_node_t* node) {
    if (!node) {
        return 0;
    }

    // Count left/right children + self
    return count_nodes_impl(node->left) + count_nodes_impl(node->right) + 1;
}

int count_nodes(BTree tree) {
    return count_nodes_impl(tree->head);
}

static int get_height_impl(tree_node_t* node) {
    if (!node) {
        // Node doesn't exist, return -1 to account for additional +1 on root node
        return -1;
    }

    // Compute height of left and right
    int left_height = get_height_impl(node->left);
    int right_height = get_height_impl(node->right);

    // Return self + max of left/right heights
    if (left_height > right_height) {
        return 1 + left_height;
    }

    return 1 + right_height;
}

int get_height(BTree tree) {
    if (!tree->head) {
        // Ensure empty tree returns 0 instead of -1
        return 0;
    }

    return get_height_impl(tree->head);
}

static void destroy_impl(tree_node_t* node) {
    if (!node) {
        return;
    }

    // Free all children
    destroy_impl(node->left);
    destroy_impl(node->right);

    // Free self
    free(node);
}

void destroy_tree(BTree tree) {
    // Free nodes
    destroy_impl(tree->head);

    // Free self
    free(tree);
}