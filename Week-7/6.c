// 6. Write a program to implement priority queue.

#include <stdio.h>
#define MAX 5

int queue[MAX];
int priority[MAX];
int size = 0;

void enqueue(int value,int p){
    int i;
    if(size == MAX){
        pritnf("Priority Queue Overflow.\n");
        return;
    }
    queue[size] = value;
    priority[size] = p;
    size++;

}

void dequeue(){
    int i;
    int highest;
    int value;
    if(size == 0){
        printf("Priority Queue Underflow\n");
        return;
    }
    highest = 0;
    for(i = 1; i<size; i++){
        if(priority[i] < priority[highest]){
            highest = i;
        }
    }
    value = queue[highest];
    for(int i = highest; i < size -1 ;i++){
        queue[i] = queue[i+1];
        priority[i] = priority[i+1];
    }
    size--;
}

void display()
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Priority Queue:\n");

    for (i = 0; i < size; i++)
    {
        printf("Value = %d, Priority = %d\n",
               queue[i], priority[i]);
    }
}

int main()
{
    enqueue(10, 3);
    enqueue(20, 1);
    enqueue(30, 2);
    enqueue(40, 4);

    printf("\nBefore Deletion:\n");
    display();

    printf("\nDeletion:\n");
    dequeue();

    printf("\nAfter Deletion:\n");
    display();

    return 0;
}
