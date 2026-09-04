// Design a program to create a singly linked list containing both even and odd numbers. 
// Find out the sum of all even numbers in the list, followed by the sum of all odd numbers. 
// Lastly, find out their difference.

#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main() {
    
    struct Node *head = NULL, *temp = NULL;
    int n,value;
    int evenSum = 0,oddSum = 0;

    printf("Enter number of Elements: ");
    scanf("%d",&n);

    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++){
        struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
        scanf("%d",&value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
    }

    temp = head;
    while(temp != NULL){
        if(temp->data % 2 == 0){
            evenSum += temp->data;
        }
        else{
            oddSum += temp->data;
        }
        temp = temp->next;
    }

    printf("Sum of even numbers = %d\n", evenSum);
    printf("Sum of odd numbers = %d\n", oddSum);
    printf("Difference = %d\n", abs(evenSum - oddSum));

    return 0;
}