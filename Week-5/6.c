#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

// Insert at beginning
struct Node* insertBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    struct Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    return newNode; // new head
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    struct Node* last = head->prev;
    last->next = newNode;
    newNode->prev = last;
    newNode->next = head;
    head->prev = newNode;
    return head;
}

// Insert at position (1-based)
struct Node* insertAtPos(struct Node* head, int data, int pos) {
    if (pos == 1) return insertBeginning(head, data);
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; i < pos-1 && temp->next != head; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

// Delete from beginning
struct Node* deleteBeginning(struct Node* head) {
    if (head == NULL) return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* last = head->prev;
    struct Node* newHead = head->next;
    last->next = newHead;
    newHead->prev = last;
    free(head);
    return newHead;
}

// Delete from end
struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* last = head->prev;
    struct Node* newLast = last->prev;
    newLast->next = head;
    head->prev = newLast;
    free(last);
    return head;
}

// Delete from position
struct Node* deleteAtPos(struct Node* head, int pos) {
    if (head == NULL) return NULL;
    if (pos == 1) return deleteBeginning(head);
    struct Node* temp = head;
    for (int i = 1; i < pos && temp->next != head; i++) {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return head;
}

// Print list forward
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Forward Traversal:\n");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");

    printf("Backward Traversal:\n");
    temp = head->prev;
    do {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("(back to tail)\n");
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
