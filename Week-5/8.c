// Write a program to divide doubly linked list from middle and rejoin them in reverse manner.
// Sample input: 1 -> 2 -> 3 -> 4 - > 5 -> 6
// Output: 3 -> 2 -> 1 -> 6 -> 5 -> 4

#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* insert(struct Node* head,int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head == NULL){
        return newNode;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

struct Node* reverse(struct Node *head)
{
    struct Node *temp = NULL;
    struct Node *current = head;

    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if(temp != NULL)
        head = temp->prev;

    return head;
}

struct Node* rearrange(struct Node* head){
    struct Node* slow = head;
    struct Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node *head2 = slow->next;
    slow->next = NULL;

    if(head2 != NULL)
        head2->prev = NULL;

    struct Node *first = reverse(head);
    struct Node *second = reverse(head2);

    struct Node *temp = first;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = second;

    if(second != NULL){
        second->prev = temp;
    }
    return first;
}

void display(struct Node *head)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d <->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() {
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);

    printf("Original List: \n");
    display(head);

    head = rearrange(head);

    printf("\nModified List: \n");
    display(head);

    return 0;
}