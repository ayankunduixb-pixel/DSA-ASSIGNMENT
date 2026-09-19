// Write a program to check whether a tree is full or complete.

#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isFull(struct Node* root){
    // Empty tree is full
    if(root == NULL){
        return 1;
    }

    // Leaf Node
    if(root->left == NULL && root->right == NULL){
        return 1;
    }

    // Node has only one child
    if(root->left == NULL || root->right == NULL){
        return 0;
    }

    return isFull(root->left) && isFull(root->right);
}

// Count total number of nodes
int countNodes(struct Node *root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check whether the tree is complete

int isComplete(struct Node *root,int index,int totalNodes){
    // Empty tree
    if(root == NULL){
        return 1;
    }
    // If index becomes greater than or equal to total Nodes
    if(index >= totalNodes){
        return 0;
    }
    return isComplete(root->left , (2 * index)+1 , totalNodes) &&
           isComplete(root->right,2 * index +2, totalNodes);
}

int main() {
    struct Node *root;
    int totalNodes;

    root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    totalNodes = countNodes(root);

    // Check Full Binary Tree
    if(isFull(root)){
        printf("The tree is a Full Binary Tree.\n");
    }
    else{
        printf("The tree is Not a full Binary Tree\n");
    }

    // Check Complete Binary Tree
    if (isComplete(root, 0, totalNodes)) {
        printf("The tree is a Complete Binary Tree.\n");
    } else {
        printf("The tree is NOT a Complete Binary Tree.\n");
    }

    return 0;
}