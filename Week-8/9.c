// Write a program for AVL Tree rotations: LL, RR, LR, RL.

#include <stdio.h>
#include<stdlib.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *n){
    if(n == NULL)
        return 0;
    return n->height;
}

struct Node *createNode(int key){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

int getBalanceFactor(struct Node *n){
    if(n == NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct Node* leftRotate(struct Node* x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    y->height = max(getHeight(y->right),getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right),getHeight(x->left)) + 1;
    
    return x;
}

struct Node* rightRotate(struct Node* y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right),getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right),getHeight(x->left)) + 1;

    return x;
}

struct Node *insert(struct Node* node,int key){
    if(node == NULL){
        return (createNode(key));
    }
    if(key < node->key){
        node->left = insert(node->left,key);
    }
    else if(key > node->key){
        node->right = insert(node->right,key);
        return node;
    }

    node->height = max(getHeight(node->right),getHeight(node->left)) + 1;
    int bf = getBalanceFactor(node);

    // Left-Left case
    if(bf > 1 && key < node->left->key){
        
    }

    // Right-Right case
    // Left-Right case
    // Right-Left case
}
int main() {
    
    return 0;
}