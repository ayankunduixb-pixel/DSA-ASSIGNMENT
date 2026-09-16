// Write a program to implement a doubly linked list.
#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head){
    struct Node* temp = head;
    printf("Forward Traversal:\n");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        if (temp->next == NULL) break; // stop at last node
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Backward Traversal:\n");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = createNode(10);
    second = createNode(20);
    third = createNode(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Doubly Linked List:\n");
    printList(head);

    return 0;
}