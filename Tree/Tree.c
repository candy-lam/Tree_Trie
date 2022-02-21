#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Tree.h"
#include "TreeNode.h"

struct TreeCDT{
    TreeNodeADT rt;
    int nrSubtrees;
    TreeADT substree[100];
    // The maximum number of subtrees is 100.
    // If nrSubtrees = k, then only subtree[0] to subtree[k-1] are used.
};

TreeADT EmptyTree(){
    return (TreeADT) NULL;
}

TreeADT NonemptyTree(TreeNodeADT N, int childNum, ...){
    // The first argument is the root;
    // The second argument is the number of children of the root;
    // The other arguments are subtrees of type TreeADT.
    TreeADT t = (TreeADT)malloc(sizeof(*t));
    t->rt = N;
    t->nrSubtrees = childNum;

    va_list args;
    TreeADT sub = (TreeADT)malloc(sizeof(*sub));

    va_start(args, childNum);
    for (int k = 0; k < childNum; k++){
        sub = va_arg(args, TreeADT);
    }

    va_end(args);
    return t;
}

TreeADT AddSubtree(TreeADT parent, TreeADT sub){ // The second arguments is added to the first argument as a subtree
    if (TreeIsEmpty(parent)) {
        printf("Parent tree not exist.");
        exit(EXIT_FAILURE);
    }
    if (TreeIsEmpty(sub)) {
        printf("Subtree not exist.");
        exit(EXIT_FAILURE);
    }
    parent->substree[parent->nrSubtrees] = sub;
    parent->nrSubtrees++;
    return parent;
}

TreeADT Subtree(int n, TreeADT t){ // Returns the nth subtree where n is given in the first argument. n = 0, 1, 2, ...
    if (TreeIsEmpty(t)) {
        printf("Tree not exist.");
        exit(EXIT_FAILURE);
    }
    return t->substree[n];
}

int NumberOfSubtrees(TreeADT t){ // number of children of the root
    if (TreeIsEmpty(t)){
        printf("Tree not exist.");
        exit(EXIT_FAILURE);
    }
    return t->nrSubtrees;
}

bool TreeIsEmpty(TreeADT t){
    return t == (TreeADT) NULL;
}

TreeNodeADT Root(TreeADT t){
    if (TreeIsEmpty(t)) {
        printf("Tree not exist.");
        exit(EXIT_FAILURE);
    }
    return t->rt;
}
