// Write a program to convert a string into a linked list of characters.
#include <stdio.h>
#include<stdlib.h>

struct Node{
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
        printf("%c-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s",str);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for(int i=0; str[i] != '\0'; i++){
        struct Node* newNode = createNode(str[i]);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Linked list of characters:\n");
    printList(head);

    return 0;
}