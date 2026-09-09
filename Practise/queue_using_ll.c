#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    struct Node* temp = front;
    if(front == NULL && rear == NULL){
        printf("Queue underflow\n");
    }
    else{
        front = front->next;
        free(temp);
    }
}

void display(){
    struct Node* temp;
    if(front == 0 && rear == 0){
        printf("Queue is empty\n");
    }
    else{
        struct Node* temp = front;
        while(temp != NULL){
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void peek(){
    if(front == NULL && rear == NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("%d\n",front->data);
    }
}

int main() {
    enqueue(5);
    enqueue(2);
    enqueue(-3);
    display();
    dequeue();
    peek();
    display();
    return 0;
}