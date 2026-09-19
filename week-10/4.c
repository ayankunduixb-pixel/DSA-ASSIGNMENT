// Write a program to create a binary search tree.

#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root,int data){
    if(root == NULL){
        return createNode(data);
    }

    if(data < root->data){
        root->left = insert(root->left,data);
    }

    else if(data > root->data){
        root->right = insert(root->right,data);
    }
    return root;
}

void inorder(struct Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main() {
    struct Node *root = NULL;
    int n,data,i;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i = 0;i<n;i++){
        printf("Enter data: ");
        scanf("%d",&data);

        root = insert(root,data);
    }

    printf("\nIndorder Traversal of BST: ");
    inorder(root);
    return 0;
}