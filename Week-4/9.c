// Given a singly linked list of size N. The task is to swap elements in the linked list pair
// wise. For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.
#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* pairWiseSwap(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL && temp->next != NULL){
        int t = temp->data;
        temp->data = temp->next->data;
        temp->next->data = t;

        temp = temp->next->next;
    }
    return head;
}

struct Node* insertTail(struct Node* head,int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL){
        return newNode;
    }
    struct Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() {
    struct Node* head = NULL;
    head = insertTail(head,1);
    head = insertTail(head,2);
    head = insertTail(head,3);
    head = insertTail(head,4);

    printf("Original List: \n");
    printList(head);

    head = pairWiseSwap(head);

    printf("\nAfter Pairwise Swap: \n");
    printList(head);

    return 0;
}