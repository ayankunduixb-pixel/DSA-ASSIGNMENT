// 4. Write a Program to implement multiple queues using a single array
#include <stdio.h>

#define MAX 30
#define Q 3

int arr[MAX];

typedef struct{
    int front;
    int rear;
    int start;
    int end;
} Queue;

Queue queues[Q];

void initQueues(){
    int sizePerQueue = MAX / Q;
    for(int i = 0; i < Q ; i++){
        queues[i].front = -1;
        queues[i].rear = -1;

        queues[i].start = i * sizePerQueue;
        queues[i].end = (i+1) * sizePerQueue - 1;
    }
}

int isEmpty(int qn){
    return queues[qn].front == -1;
}

int isFull(int qn){
    return queues[qn].rear == queues[qn].end;
}

void enqueue(int qn,int value){
    if(qn < 0 || qn >= Q){
        printf("Invalid Queue Number\n");
        return;
    }
    if(isFull(qn)){
        printf("Queue %d is Full\n",qn);
        return;
    }
    if(isEmpty(qn)){
        queues[qn].front = queues[qn].start;
        queues[qn].rear = queues[qn].start;
    }
    else{
        queues[qn].rear++;
    }
    arr[queues[qn].rear] = value;

    printf("%d inserted into Queue %d\n",value,qn);
}

void dequeue(int qn)
{
    int value;

    if (qn < 0 || qn >= Q)
    {
        printf("Invalid Queue Number\n");
        return;
    }

    if (isEmpty(qn))
    {
        printf("Queue %d is Empty\n", qn);
        return;
    }

    value = arr[queues[qn].front];

    if (queues[qn].front == queues[qn].rear)
    {
        queues[qn].front = -1;
        queues[qn].rear = -1;
    }
    else
    {
        queues[qn].front++;
    }

    printf("%d deleted from Queue %d\n", value, qn);
}

void display(int qn)
{
    int i;

    if (qn < 0 || qn >= Q)
    {
        printf("Invalid Queue Number\n");
        return;
    }

    if (isEmpty(qn))
    {
        printf("Queue %d is Empty\n", qn);
        return;
    }

    printf("Queue %d: ", qn);

    for (i = queues[qn].front; i <= queues[qn].rear; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    initQueues();

    // Insert elements
    enqueue(0, 10);
    enqueue(0, 20);
    enqueue(0, 30);

    enqueue(1, 40);
    enqueue(1, 50);

    enqueue(2, 60);
    enqueue(2, 70);
    enqueue(2, 80);

    // Display queues
    printf("\nBefore Deletion:\n");

    display(0);
    display(1);
    display(2);

    // Delete elements
    printf("\nDeletion:\n");

    dequeue(0);
    dequeue(2);

    // Display after deletion
    printf("\nAfter Deletion:\n");

    display(0);
    display(1);
    display(2);

    return 0;
}