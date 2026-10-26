// Check if a sub array with 0 sum exists or not.

#include <stdio.h>
#include<stdlib.h>

#define SIZE 100

struct Node{
    int key;
    struct Node *next;
};

struct Node *hashTable[SIZE];

int hash(int key){
    if(key < 0){
        key = -key;
    }
    return key % SIZE;
}

int search(int key){
    int index = hash(key);
    struct Node *temp = hashTable[index];

    while(temp != NULL){
        if(temp->key == key){
            return 1;

            temp = temp->next;
        }
    }
    return 0;
}

void insert(int key){
    int index = hash(key);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int main() {
    int n,i , sum = 0 ,found = 0;

    printf("Enter number of elemnets: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the elemnets: ");

    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    insert(0)
    return 0;
}