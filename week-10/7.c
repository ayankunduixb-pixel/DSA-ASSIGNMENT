// Write a program to implement at two way threaded binary tree.

#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    int lthread;
    int rthread;
};

struct Node* createNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    newNode->lthread = 1;
    newNode->rthread = 1;
    return newNode;
}

struct Node* insert(struct Node *root,int data){
    struct Node *current = root;
    struct Node *parent = NULL;
    struct Node *newNode;

    while (current != NULL) {

        if (data == current->data) {
            printf("Duplicate value not allowed.\n");
            return root;
        }

        parent = current;

        if (data < current->data) {

            if (current->lthread == 0)
                current = current->left;
            else
                break;
        }
        else {

            if (current->rthread == 0)
                current = current->right;
            else
                break;
        }
    }

    newNode = createNode(data);

    // First node
    if (parent == NULL) {
        root = newNode;
        return root;
    }

    // Insert as left child
    if (data < parent->data) {

        newNode->left = parent->left;
        newNode->right = parent;

        parent->lthread = 0;
        parent->left = newNode;
    }

    // Insert as right child
    else {

        newNode->left = parent;
        newNode->right = parent->right;

        parent->rthread = 0;
        parent->right = newNode;
    }

    return root;
}

// Find the leftmost node
struct Node* leftMost(struct Node *root) {

    if (root == NULL)
        return NULL;

    while (root->lthread == 0) {
        root = root->left;
    }

    return root;
}

// Inorder traversal
void inorder(struct Node *root) {

    struct Node *current;

    current = leftMost(root);

    while (current != NULL) {

        printf("%d ", current->data);

        // If right pointer is a thread
        if (current->rthread == 1) {
            current = current->right;
        }

        // Otherwise find leftmost node
        else {
            current = leftMost(current->right);
        }
    }
}

int main() {

    struct Node *root = NULL;
    int n, data, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++) {

        scanf("%d", &data);

        root = insert(root, data);
    }

    printf("\nInorder Traversal of Two-Way Threaded Binary Tree:\n");

    inorder(root);

    return 0;
}