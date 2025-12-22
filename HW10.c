#include <stdio.h>

#define MAX_NODES 15 
char tree[MAX_NODES];

void init() {
    for (int i = 0; i < MAX_NODES; i++) {
        tree[i] = '-'; 
    }
}

void setRoot(char key) {
    tree[0] = key;
}

void setLeft(char key, int parentIndex) {
    int leftIndex = (2 * parentIndex) + 1;
    if (tree[parentIndex] == '-') {
        printf("Not found \n");
    } else {
        tree[leftIndex] = key;
    }
}

void setRight(char key, int parentIndex) {
    int rightIndex = (2 * parentIndex) + 2;
    if (tree[parentIndex] == '-') {
        printf("Not found\n");
    } else {
        tree[rightIndex] = key;
    }
}

void printTree() {
    for (int i = 0; i < MAX_NODES; i++) {
        if (tree[i] != '-')
            printf("Node %d: %c\n", i, tree[i]);
    }
}

int main() {
    init();
    setRoot('A');      
    setLeft('B', 0);   
    setRight('C', 0);  
    setLeft('D', 1);   
    setRight('E', 1);  

    printf("Binary Tree Array Representation:\n");
    printTree();

    return 0;
}