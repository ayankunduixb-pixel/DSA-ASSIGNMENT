// Demonstrate the logic of deleting a node from the last of a doubly circular linked list
// with code in c

#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* deleteLast(struct Node *head){
    struct Node *last;
    struct Node *newLast;
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    if(head->next == head){
        free(head);
        return NULL;
    }
    last = head->prev;
    newLast = last->prev;
    newLast->next = head;
    head->prev = newLast;
    free(last);
    return head;
}

void display(struct Node *head)
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("\n");
}

int main() {
    struct Node *head;
    struct Node *n1;
    struct Node *n2;
    struct Node *n3;
    struct Node *n4;

    // Create nodes
    n1 = malloc(sizeof(struct Node));
    n2 = malloc(sizeof(struct Node));
    n3 = malloc(sizeof(struct Node));
    n4 = malloc(sizeof(struct Node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    n4->data = 40;

    // Connect nodes
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n1;

    n1->prev = n4;
    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;

    head = n1;

    printf("Before deletion: ");
    display(head);

    head = deleteLast(head);

    printf("After deletion: ");
    display(head);
    return 0;
}