// Write a program to perform insertion of an element/node in a given list.
#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void insertAtPos(struct Node* head, int data, int pos){
    struct Node* newNode = createNode(data);
    if(pos == 0){
        newNode->next = 
    }
}

int main() {
    
    return 0;
}