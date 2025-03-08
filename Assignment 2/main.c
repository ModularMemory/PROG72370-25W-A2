#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "tree.h"

/// <summary>
/// Generates a random number inclusively between min_incl and max_excl - 1
/// </summary>
static unsigned int rand_range(unsigned int min_incl, unsigned int max_excl) {
    assert(min_incl < max_excl);
    return rand() % (max_excl - min_incl) + min_incl;
}

int main(void) {
    srand(time(NULL));

    BTree tree = create_tree();

    int insert_count = rand_range(11, 21);
    printf("Inserting %d chars into the tree...\n", insert_count);

    for (int i = 0; i < insert_count; i++) {
        char c = (char)rand_range('a', 'z' + 1);
        insert(tree, c);
    }

    for (char c = 'a'; c <= 'z'; c++) {
        if (contains(tree, c)) {
            printf("The tree contains '%c'\n", c);
        }
    }

    printf("The tree has %d nodes.\n", count_nodes(tree));

    printf("The tree is %d layers tall.\n", get_height(tree));

    destroy_tree(tree);

    return 0;
}