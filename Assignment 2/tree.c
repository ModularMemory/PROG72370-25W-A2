#include "tree.h"

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
