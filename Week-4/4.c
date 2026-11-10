// Write a program to perform insertion of an element/node in a given list.
#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct node *head = NULL;

// struct Node* createNode(int data){
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

void display(){
    struct Node* temp = head;

    printf("Linked List: ");

    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void insertAtPos(int value, int pos){
    struct Node *temp;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;

    for(int i = 1; i<pos-1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Invalid Position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    int n, value,pos,i;
    struct Node *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i = 0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&value);

        newNode = (struct Node*)malloc(sizeof(struct Node));

        if(newNode == NULL){
            printf("Memory allocation failed!\n");
            return 1;
        }

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
        }
        else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    printf("Enter element to insert: ");
    scanf("%d",&value);

    printf("Enter position: ");
    scanf("%d",&pos);

    insertAtPos(value,pos);
    display();

    return 0;
}