#ifndef LIST_H
#define LIST_H
#include "Trie.h"

typedef struct listCDT *listADT;

typedef TrieADT listElementT;

listADT EmptyList(void);
listADT Cons(listElementT, listADT);
listElementT Head(listADT);
listADT Tail(listADT);
int ListIsEmpty(listADT);


#endif
