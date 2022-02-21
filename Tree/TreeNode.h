#ifndef TREENODE_H
#define TREENODE_H
#include <stdlib.h>

typedef struct TreeNodeCDT *TreeNodeADT;
typedef char NodeContentT; //For simplicity, we only store one character in a node.

TreeNodeADT NewNode(NodeContentT);
NodeContentT GetNodeContent(TreeNodeADT);

#endif // TREENODE_H
