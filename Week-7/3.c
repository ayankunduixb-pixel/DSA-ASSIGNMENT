// 3. Write a program to implement circular queue.

#include <stdio.h>
#include<stdlib.h>
# define MAX 5


int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int value){
    if(front == -1 && rear == -1){
        front  = rear = 0;
        queue[rear] = value;
    }
    else if(((rear+1) % MAX) == front){
        printf("Queue overflow");
    }
    else{
        rear = (rear + 1) % MAX;
        queue[rear] = value;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue Underflow");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front+1) % MAX;
    }
}

void display(){
    int i = front;
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements: ");
        while(i != rear){
            printf("%d ",queue[i]);
            i = (i+1)% MAX;
        }
        printf("%d",queue[rear]);
    }
}

int main() {
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    dequeue();
    return 0;
}