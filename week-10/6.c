// Write a program to find mirror image of a BST.

#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data){
    struct Node *newNode;
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

void mirror(struct Node *root){
    struct Node *temp;
    if(root == NULL){
        return;
    }
    temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Mirror left subtree
    mirror(root->left);

    // Mirror left subtree
    mirror(root->right);
}

void preorder(struct Node *root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    struct Node *root = NULL;
    int n,data,i;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter the elements: \n");
    for(int i = 0;i<n;i++){
        scanf("%d",&data);
        root = insert(root,data);
    }
    
    printf("\nOriginal BST (Preorder): ");
    preorder(root);

    mirror(root);

    printf("\nMirror Image (Preorder): ");
    preorder(root);

    return 0;
}