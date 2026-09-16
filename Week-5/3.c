// Write a program to implement a doubly circular linked list.

#include <stdio.h>
#include<stdlib.h>

struct Node{
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

struct Node* insertEnd(struct Node* head,int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        return newNode;
    }
    struct Node* last = head->prev;
    last->next = newNode;
    newNode->prev = last;
    newNode->next = head;
    head->prev = newNode;
    return head;
}


void printList(struct Node* head){
    if(head == NULL) return;
    struct Node* temp = head;
    printf("Forward Traversal:\n");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");

    printf("Backward Traversal:\n");
    temp = head->prev;
    do {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("(back to tail)\n");
}

int main() {
    struct Node* head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    printf("Doubly Circular Linked List:\n");
    printList(head);
    return 0;
}