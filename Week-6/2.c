// Write a program to implement stack using linked list.

#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push operation
void push(int value){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed into stack\n", value);
}

void pop(){
    struct Node* temp;
    if(top == NULL){
        printf("Stack underflow");
        return;
    }
    temp = top;
    printf("%d popped from stack\n",top->data);
    top = top->next;
    free(temp);
}

void peek(){
    if(top == NULL){
        printf("Stack is empty\n");
    } else{
        printf("Top element: %d\n",top->data);
    }
}

void display(){
    struct Node* temp;
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    temp = top;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    peek();

    pop();

    display();
    return 0;
}