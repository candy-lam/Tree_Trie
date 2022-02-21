#include <stdlib.h>
#include "TreeNode.h"

struct TreeNodeCDT{ NodeContentT NodeContent; };

TreeNodeADT NewNode(NodeContentT C) {
    TreeNodeADT N = (TreeNodeADT)malloc(sizeof(*N));
    N->NodeContent = C;
    return N;
}

NodeContentT GetNodeContent(TreeNodeADT N){
    return N->NodeContent;
}
