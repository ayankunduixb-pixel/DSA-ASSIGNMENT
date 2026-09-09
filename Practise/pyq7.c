// Demonstrate the logic of insertion of a new node before a given node in a linked list

#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int value){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

struct Node* insertBefore(struct Node *head,int key,int value){
    struct Node *newNode;
    struct Node *temp;

    newNode = createNode(value);
    if(head != NULL && head->data == key){
        newNode->next = head;
        return newNode;
    }
    temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->data == key)
        {
            newNode->next = temp->next;
            temp->next = newNode;

            return head;
        }

        temp = temp->next;
    }

    printf("Given node not found\n");
    free(newNode);

    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    struct Node *head;

    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Before insertion: ");
    display(head);

    head = insertBefore(head, 30, 25);

    printf("After insertion: ");
    display(head);

    return 0;
}