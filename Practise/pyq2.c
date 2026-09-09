#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert at beginning
struct Node* insertBeg(int value, struct Node *head) {
    struct Node *newNode;

    newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;

    return newNode;
}

// Delete at end
struct Node* deleteEnd(struct Node *head) {
    struct Node *temp;

    if (head == NULL) {
        printf("List is Empty\n");
        return NULL;
    }

    // Only one node
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return head;
}

// Display
void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    head = insertBeg(30, head);
    head = insertBeg(20, head);
    head = insertBeg(10, head);

    printf("List after insertion:\n");
    display(head);

    head = deleteEnd(head);

    printf("List after deleting from end:\n");
    display(head);

    return 0;
}