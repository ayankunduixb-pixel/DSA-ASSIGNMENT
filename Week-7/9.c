// Write a program to reverse a queue.

#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1,rear = -1;

void enqueue(int item){
    if(rear == MAX-1){
        printf("Queue overflow");
        return;
    }
    if(front == -1){
        front = 0;
    }
    queue[++rear] = item;
}

int dequeue(){
    if(front == -1 || front > rear){
        printf("Queue underflow");
        return -1;
    }
    return queue[front++];
}

void reverseQueue(){
    int stack[MAX];
    int top = -1;
    
    // Move queue elements to stack
    while(front <= rear){
        stack[++top] = dequeue();
    }

    // Move stack elements back to queue
    front = rear = -1;
    while(top >= 0){
        enqueue(stack[top--]);
    }
}

void display(){
    if(front == -1 || front > rear){
        printf("Queue is empty");
        return;
    }
    for(int i = front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Original Queue: ");
    display();

    reverseQueue();

    printf("Reversed Queue: ");
    display();

    return 0;
}