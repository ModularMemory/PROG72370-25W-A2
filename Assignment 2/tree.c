#include "tree.h"

static tree_node_t* insertImpl(tree_node_t* tree, char data) {}

void insert(tree_node_t** tree, char data) {
    *tree = insertImpl(tree, data);
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

int countNodes(tree_node_t* tree) {
    if (!tree) {
        return 0;
    }

    return countNodes(tree->left) + countNodes(tree->right) + 1;
}

int getHeight(tree_node_t* tree) {
    if (!tree) {
        return -1;
    }

    int left = getHeight(tree->left);
    int right = getHeight(tree->right);

    if (left > right) {
        return 1 + left;
    }

    return 1 + right;
}
