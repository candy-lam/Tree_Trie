#ifndef TREE_H
#define TREE_H
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TreeNode.h"

typedef struct TreeCDT *TreeADT;

TreeADT EmptyTree(void);
TreeADT NonemptyTree(TreeNodeADT, int, ...);
    // The first argument is the root;
    // The second argument is the number of children of the root;
    // The other arguments are subtrees of type TreeADT.
TreeADT AddSubtree(TreeADT, TreeADT);
    // The second arguments is added to the first argument as a subtree
TreeADT Subtree(int, TreeADT);
    // Returns the nth subtree where n is given in the first argument. n = 0, 1, 2, ...
int NumberOfSubtrees(TreeADT); // number of children of the root
bool TreeIsEmpty(TreeADT);
TreeNodeADT Root(TreeADT);


#endif // TREE_H
