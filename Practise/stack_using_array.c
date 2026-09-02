#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int val){
    if(top == MAX-1){
        printf("Stack Overflow\n");
    }
    else{
        stack[++top] = val;
        printf("%d pushed\n",val);
    }
}

void pop(){
    if(top == -1){
        printf("Stack Underflow");
    }
    else{
        printf("%d popped\n",stack[top]);
        stack[top--];
    }
}

void display(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements: ");
        for(int i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}

int peek(){
    if(top == -1){
        printf("Stack is empty");
        return -1;
    }
    else{
        return stack[top];
    }
}

int isEmpty(){
    return (top == -1);
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}