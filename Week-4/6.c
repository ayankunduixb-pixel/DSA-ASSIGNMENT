// Write a program to perform deletion of an element/node in a given list.

#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void display(){
    struct Node* temp = head;

    printf("Linked List: ");
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }

    printf("NULL");
}

int main() {
    
    return 0;
}