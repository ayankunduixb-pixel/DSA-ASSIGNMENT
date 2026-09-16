// Write a program to perform insertion & deletion of elements at different
// position of doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertBeginning(struct Node* head, int data){
    struct Node* newNode = createNode(data);
    if(head == NULL) return newNode;
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data){
    struct Node* newNode = createNode(data);
    if(head == NULL) return newNode;
    struct Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Node* insertAtPos(struct Node* head, int data, int pos){
    if(pos == 1) return insertBeginning(head,data);
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for(int i=1;i<pos-1 && temp->next != NULL; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Node* deleteBeginning(struct Node* head){
    if(head == NULL) return NULL;
    struct Node* temp = head;
    head = head->next;
    if(head != NULL) head->prev = NULL;
    free(temp);
    return head;
}

struct Node* deleteEnd(struct Node* head){
    if(head == NULL) return NULL;
    struct Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    if(temp->prev != NULL) temp->prev->next = NULL;
    else head = NULL; // only one node
    free(temp);
    return head;
}

struct Node* deleteAtPos(struct Node* head, int pos) {
    if (head == NULL) return NULL;
    if (pos == 1) return deleteBeginning(head);
    struct Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return head;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
    return head;
}

// Print list forward
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("Forward Traversal:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    printList(head);

    head = insertBeginning(head, 5);
    printList(head);

    head = insertAtPos(head, 15, 3);
    printList(head);

    head = deleteBeginning(head);
    printList(head);

    head = deleteEnd(head);
    printList(head);

    head = deleteAtPos(head, 2);
    printList(head);

    return 0;
}