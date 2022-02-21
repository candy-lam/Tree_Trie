#include <stdlib.h>
#include <stdbool.h>
#include "Trie.h"

struct TrieCDT {
    int weight;
    char c;
    TrieADT L, R;
};
// For leave nodes, L and R are both NULL.
// For non-leave nodes, c is not used.

TrieADT Leaf(char a, int f){
    TrieADT t = (TrieADT)malloc(sizeof(*t));
    t->weight = f;
    t->c = a;
    t->L = (TrieADT) NULL;
    t->R = (TrieADT) NULL;
    return t;
}

bool IsLeaf(TrieADT t){
    return t->L == (TrieADT) NULL;
}

TrieADT NewTrie(TrieADT t1, TrieADT t2){ // constructed using two existing tries.
    TrieADT newT = (TrieADT)malloc(sizeof(*newT));
    newT->weight = t1->weight + t2->weight;
    newT->c = NULL;
    newT->L = t1;
    newT->R = t2;
    return newT;
}

int GetWeight(TrieADT t){
    return (t->weight);
}

char GetChar(TrieADT t){
    return (t->c);
}

TrieADT LeftTrie(TrieADT t){
    return (t->L);
}

TrieADT RightTrie(TrieADT t){
    return (t->R);
}
