#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[10]; 
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char* value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, value);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printInOrder(struct Node* root) {
    if (root == NULL) return;
    
    if (root->left) printf("("); 
    printInOrder(root->left);
    printf(" %s ", root->data);
    printInOrder(root->right);
    if (root->right) printf(")");
}

int main() {
    
    struct Node* nodeMult = createNode("*");
    nodeMult->left = createNode("c");
    nodeMult->right = createNode("2");

    struct Node* nodePlus = createNode("+");
    nodePlus->left = createNode("b");
    nodePlus->right = nodeMult;

    struct Node* root = createNode("=");
    root->left = createNode("a");
    root->right = nodePlus;

    printf("Abstract Syntax Tree (In-order traversal):\n");
    printInOrder(root);
    printf("\n");

    return 0;
}