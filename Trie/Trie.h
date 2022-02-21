#ifndef TRIE_H
#define TRIE_H
#include <stdlib.h>
#include <stdbool.h>

typedef struct TrieCDT *TrieADT;

TrieADT Leaf(char, int);
TrieADT NewTrie(TrieADT, TrieADT); // constructed using two existing tries.
int GetWeight(TrieADT);
char GetChar(TrieADT);
TrieADT LeftTrie(TrieADT);
TrieADT RightTrie(TrieADT);
bool IsLeaf(TrieADT);


#endif // TRIE_H
