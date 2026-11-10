// Write a program to perform modification of an element/node in a given list.
#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void modify(int pos,int newData){
    struct Node* temp = head;

    for(int i = 0;i<pos && temp != NULL;i++){
        temp = temp->next;
    }
    
    if(temp == NULL){
        printf("Invalid position!\n");
        return;
    }

    temp->data = newData;

    printf("Node modified successfully");
}

void display(){
    struct Node* temp = head;
    printf("Linked List: ");

    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n,data,pos,newData;
    struct Node *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i = 0;i<n;i++){
        printf("Enter data: ");
        scanf("%d",&data);

        newNode = (struct Node*)malloc(sizeof(struct Node));

        if(newNode == NULL){
            printf("Memory allocation failed\n");
            return 1;
        }

        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
        } else{
            temp = head;

            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    printf("\nOriginal ");
    display();

    printf("Enter position to modify (starting from 0)"); 
    scanf("%d",&pos);

    printf("Enter new data: ");
    scanf("5d",&newData);

    if(pos < 0) printf("Invalid position!\n");
    else{
        modify(pos,newData);
        display();
    }

    return 0;
}