// 5. Write a program to implement ‘Dequeue’(Using Circular Array).
#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

void insertFront(int value){
    if(front == (rear + 1) % MAX){
        printf("Queue is full");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        deque[front] = value;
    }
    else if(front == 0){
        front = MAX - 1;
        deque[front] = value;
    }
    else{
        front--;
        deque[front] = value;
    }
}

void insertRear(int value){
    if(front == (rear + 1) % MAX){
        printf("Queue is full");
    }
    else if(front == -1 && rear ==-1){
        front = rear = 0;
        deque[rear] = value;
    }
    else if(rear == MAX-1){
        rear = 0;
        deque[MAX] = value;
    }
    else{
        rear++;
        deque[rear] = value;
    }
}

void deleteFront(){
    if(front == -1 && rear == -1){
        printf("Queue underflow");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else if(front == MAX-1){
        // printf("%d",deque[front]);
        front = 0;
    }
    else{
        // printf("%d",deque[front]);
        front++;
    }
}

void deleteRear(){
    if(front == -1 && rear == -1){
        printf("Queue underflow");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else if(rear == 0){
        // printf("%d",deque[rear]);
        rear = MAX-1;
    }
    else{
        // printf("%d",deque[rear]);
        rear--;
    }

}

void display(){
    int i = front;
    while(i != rear){
        printf("%d",deque[i]);
        i = (i+1) % MAX;
    }
    printf("%d\n",deque[rear]);
}

void getFront(){
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }
    else{
        printf("%d",deque[front]);
    }
}

void getRear(){
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }
    else{
        printf("%d",deque[rear]);
    }
}



int main() {
    insertRear(10);
    insertRear(20);
    insertRear(30);

    display();

    insertFront(5);

    display();

    deleteFront();

    display();

    deleteRear();

    display();
    return 0;
}