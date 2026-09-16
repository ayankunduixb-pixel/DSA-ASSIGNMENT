// 1. Write a program to implement linear queue using array.
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 6

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value){
    if(rear == MAX-1){
        printf("Queue Overflow");
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
    if(front == -1){
        printf("Queue underflow");
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
        printf("Queue is empty");
        return;
    }
    printf("Queue elements: ");
    for(int i = front;i<=rear;i++){
        printf("%d ",queue[i]);
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

bool isEmpty(){
    return front == -1;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    display();
    return 0;
}