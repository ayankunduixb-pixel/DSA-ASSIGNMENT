#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("%d pushed\n",val);
}
void pop(){
    if(top == NULL){
        printf("Stack underflow\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped\n",top->data);
    top = top->next;
    free(temp);
}

int peek(){
    if(top == NULL){
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display(){
    if (top == NULL){
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack ELements: ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Top element: %d\n", peek());
    pop();
    display();
    return 0;
}