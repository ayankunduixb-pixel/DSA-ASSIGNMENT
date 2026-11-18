// Write a program to implement stack using array.

#include <stdio.h>

#define MAX 5

char stack[MAX];
int top = -1;

// Push operation
void push(int value){
    if(top == MAX-1){
        printf("Stack overflow");
    }
    else{
        stack[++top] = value;
        printf("%d pushed into stack\n",value);
    }
}

// Pop operation
void pop(){
    if(top == -1){
        printf("Stack underflow");
    }
    else{
        printf("%d popped from stack\n",stack[top--]);
    }
}

// Peek operation
void peek(){
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

// Display stack elements
void display(){
    if(top == -1){
        printf("Stack is Empty\n");
    }
    else{
        printf("Stack elements: ");
        for(int i = top;i>= 0;i--){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
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