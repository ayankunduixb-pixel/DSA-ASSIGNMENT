// Write a program to implement tree traversal.

#include <stdio.h>
#include <stdlib.h>

// Structure of a tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a binary tree
struct Node* createTree() {
    int data;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    // If there is no node
    if (data == -1) {
        return NULL;
    }

    // Create new node
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;

    // Create left subtree
    printf("Enter left child of %d:\n", data);
    newNode->left = createTree();

    // Create right subtree
    printf("Enter right child of %d:\n", data);
    newNode->right = createTree();

    return newNode;
}

// Inorder: Left -> Root -> Right
void inorder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder: Root -> Left -> Right
void preorder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node *root;

    // Create the tree
    printf("Create Binary Tree\n");
    root = createTree();

    // Perform traversals
    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}