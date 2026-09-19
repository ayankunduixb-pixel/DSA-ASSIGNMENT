// Write a program to create a binary tree.

#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* create(){
    int data;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data(-1 for no node): ");
    scanf("%d",&data);
    if(data == -1){
        return NULL;
    }
    newNode->data = data;
    printf("Enter left child of %d",data);
    newNode->left = create();
    printf("Enter right child of %d",data);
    newNode->right = create();
    return newNode;
}

void inorder(struct Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct Node *root){
    if(root == NULL){
        return;
    }
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root){
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main() {
    struct Node *root;

    printf("Create Binary Tree\n");
    root = create();

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);
    
    return 0;
}