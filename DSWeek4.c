#include <stdio.h>
#include <stdlib.h>


void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    newNode->data = new_data;
    newNode->next = NULL;

    if (*head_ref == NULL) { 
        newNode->prev = NULL;
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) last = last->next; 

    last->next = newNode;
    newNode->prev = last;
}



void deleteListRecursive(struct Node* head) {
    if (head == NULL) return; 
    
    deleteListRecursive(head->next);

    
    printf("Deleting node with data: %d\n", head->data);
    free(head);
}