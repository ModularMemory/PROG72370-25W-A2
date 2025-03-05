#include "tree.h"

static tree_node_t* insert_impl(tree_node_t* tree, char data) {}

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
