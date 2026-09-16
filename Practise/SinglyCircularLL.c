#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head){
    if(head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
    

}

int main() {
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    head->next = second;
    second->next = third;
    third->next = head;

    printf("Singly Circular Linked List: \n");
    printList(head);
    return 0;
}