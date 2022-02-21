/* File: main.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "Tree.h"
#include "queue.h"
#define MAXNode 256


char *BFS(TreeADT t){
    if (TreeIsEmpty(t)) return NULL; // exit if empty tree
    int len = 0; //integer variable for array length
    char *array = malloc(MAXNode * sizeof(char));
    array[len] = Root(t); // assign the root
    queueADT q = EmptyQueue();
    do{
        if (!QueueIsEmpty(q)){ // if not new queue
            len++;
            t = Dequeue(q); // dequeue the tree for current loop
            array[len] = Root(t); // assign the node of the dequeued tree to char array
        }
        for (int i = 0; i < NumberOfSubtrees(t); i++){ //enqueue all subtrees to queue q
            Enqueue(q, Subtree(i, t));
        }
    }while (!QueueIsEmpty(q)); // loop until queue is empty = all nodes is assign to array
    array[len+1] = '\0'; //end of array
    return array;
}

int *Tree2Array(TreeADT t){
    if (TreeIsEmpty(t)) return NULL; // exit if empty tree
    int* array = malloc(MAXNode * sizeof(int));
    int len = 1, nodeNum = 0;
    /*len: integer variable for array length
    nodeNum: parent number of each tree, initially 0 as tree 0 handle first;*/
    queueADT q = EmptyQueue();
    int num; // integer variable for repetition
    do{
        if (!QueueIsEmpty(q)){ // if not new queue
            t = Dequeue(q); // dequeue the tree for current loop
            nodeNum++; // change the parent number
        }
        for (int i = 0; i < NumberOfSubtrees(t); i++){ // assign nodeNum to array repeatedly(times = number of subtrees)
            array[len] = nodeNum;
            num = 1;
            len++;
        }
        for (int i = 0; i < NumberOfSubtrees(t); i++){ //enqueue all subtrees to queue q
            Enqueue(q, Subtree(i, t));
        }
    }while (!QueueIsEmpty(q)); // loop until queue is empty = all elements is assign to array
    array[len] = -1; //end of array
    return array;
}

int main()
{
    TreeADT t[100];
    TreeNodeADT R;
    int parentNum[MAXNode];
    char node[MAXNode];

    // ask for sequence of integers
    printf("Input integers\t:  ");
    scanf("%s", node);
    int i = 0;
    while (node[i] != NULL){
        parentNum[i+1] = (int) node[i] - 48;
        i++;
    }
    // ask for sequence of characters
    printf("Input characters: ");
    scanf("%s", node);

    // find length of input characters
    int len = 0;
    while (node[len] != NULL){
        len++;
    }

    // check whether input is valid (length of input characters = length of input integers -1)
    if (len != (i + 1)){
        printf("Invalid input.");
        return 0;
    }

    // sort the input
    int tempNum;
    char tempNode;
    for (int a = 1; a < len - 1; ++a){
        for (int b = 1; b < len - a; ++b){
            if (parentNum[b] > parentNum[b+1]){
                tempNum = parentNum[b];
                tempNode = node[b];
                parentNum[b] = parentNum[b+1];
                node[b] = node[b+1];
                parentNum[b+1] = tempNum;
                node[b+1] = tempNode;
            }
        }
    }

    //Task 2:
    R = node[0];// assign the root
    t[0] = NonemptyTree(R, 0); // create new tree with root node

    // build tree according to input data
    for (int i = 1; i < len; i++){
        t[i] = NonemptyTree(node[i], 0); // create subtree
        t[parentNum[i]] = AddSubtree(t[parentNum[i]], t[i]); //insert subtree to parent
    }

    // display tree
    printf("\n");
    for(int i = 0; i < len; i++)
        printf("Tree %d (%c) contains %d subtree(s).\n", i, Root(t[i]), NumberOfSubtrees(t[i]));
    printf("\n");
    //Task 3:
    // display array 1
    int* array = malloc(MAXNode * sizeof(int));
    array = Tree2Array(t[0]);
    int num = 1;
    printf("Array 1:  ");
    while (array[num] != -1){
        printf("%d", array[num]);
        num++;
    }
    printf("\n");

    // display array 2
    printf("Array 2: %s\n", BFS(t[0]));

    printf("\nEnd");
    return 0;
}
