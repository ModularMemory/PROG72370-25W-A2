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

static tree_node_t* insert_impl(tree_node_t* node, char data) {
    if (!node) {
        return create_node(data);
    }

    int a = data - node->data;
    if (a < 0) {
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

    int a = data - node->data;
    if (a == 0) {
        return true;
    }

    if (a < 0) {
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

    return count_nodes_impl(node->left) + count_nodes_impl(node->right) + 1;
}

int count_nodes(BTree tree) {
    return count_nodes_impl(tree->head);
}

static int get_height_impl(tree_node_t* node) {
    if (!node) {
        return -1;
    }

    int left = get_height_impl(node->left);
    int right = get_height_impl(node->right);

    if (left > right) {
        return 1 + left;
    }

    return 1 + right;
}

int get_height(BTree tree) {
    return get_height_impl(tree->head);
}

static void destroy_impl(tree_node_t* node) {
    if (!node) {
        return;
    }

    destroy_impl(node->left);
    destroy_impl(node->right);

    free(node);
}

void destroy_tree(BTree tree) {
    destroy_impl(tree->head);
    free(tree);
}