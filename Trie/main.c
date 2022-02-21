#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "Trie.h"
#define MAXLength 1000

listADT PutAtProperPosition(listADT L, listElementT t){ //Note that L is sorted.
    if (ListIsEmpty(L)) return Cons(t, EmptyList());
    if (GetWeight(t) < GetWeight(Head(L))) return Cons(t, L);
    return Cons(Head(L), PutAtProperPosition(Tail(L), t));
}

int main()
{
    FILE *datafile = fopen("huffman.txt","r");
    if (datafile == NULL){
        printf("File not found.");
        return 0;
    }   //if no huffman.txt found, end the program

    char readchar[MAXLength], countchar[256];
    int count = 0, c, frequency[256];

    while ((c = fgetc(datafile)) != EOF){ //Read character one by one
        readchar[count++] = (char) c;
    }
    readchar[count] = '\0'; //put an end to the array
    //printf("%s\n", readchar);

    int charNum;
    count = 0;
    // Start counting the frequency of each character
    while (readchar[count] != '\0'){ // loop when not the end of the text
        charNum = 0; //reset the counter
        do{
            if (readchar[count] == countchar[charNum]){ // +1 frequency if character is repeated
                frequency[charNum]++;
                break;
            }
            charNum++;
        }while (countchar[charNum] != '\0'); // loop when not the end of the counting array

        if (countchar[charNum] == '\0'){ // create new entry
            countchar[charNum] = readchar[count];
            frequency[charNum] = 1;
            countchar[charNum+1] = '\0'; // set new end to the counting array
        }
        count++;
    }
    //printf("CheckPoint.\n");

    charNum--;
    TrieADT leaves[charNum];
    for (int i = 0; i <= charNum; i++){ // create leaves
        leaves[i] = Leaf(countchar[i+1], frequency[i+1]);
    }

    //Sort leaves according to the frequency (descending)
    TrieADT temp;
    for (int a = 0; a < charNum - 1; ++a){
        for (int b = 0; b < charNum - 1 - a; ++b){
            if (GetWeight(leaves[b]) < GetWeight(leaves[b+1])){
                temp = leaves[b];
                leaves[b] = leaves[b+1];
                leaves[b+1] = temp;
            }
        }
    }

/*
    printf("\n");
    for (int j = 0; j <= charNum; j++){
        printf("Character:\'%c\'\tFrequency:%d\n", GetChar(leaves[j]), GetWeight(leaves[j]));

    }
*/

    listADT Q; // a list of trie leave nodes, sorted in ascending order of weight
    Q = EmptyList();

    for (int i = 0; i <= charNum; i++){ // Insert leaves into the list in ascending order
        Q = Cons(leaves[i], Q);
    }

    //printf("\n");
    TrieADT newT;

    while (!ListIsEmpty(Tail(Q))){
        newT = NewTrie(Head(Q), Head(Tail(Q)));
        Q = PutAtProperPosition(Tail(Tail(Q)), newT);

    }
    //printf("Weight After: %d\n", GetWeight(Head(Q)));

    printf("\nEnd.");
    fclose(datafile);
    return 0;
}
