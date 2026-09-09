#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value){
    if(rear == MAX -1){
        printf("Queue Overflow\n");
        return;
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = value;
    }
    else{
        rear++;
        queue[rear] = value;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue underflow\n");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Stack is empty\n");
    }
    else{
        for(int i=front;i<rear+1;i++){
            printf("%d",queue[i]);
        }
        printf("\n");
    }
}

void peek(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("%d\n",queue[front]);
    }
}

int main() {
    enqueue(2);
    enqueue(3);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();
    return 0;
}