// Write a program to collect height & weight of N students.
// Find the highest weight/height ratio using linked list.
#include <stdio.h>
#include<stdlib.h>

struct Node{
    float data;
    struct Node* next;
};

struct Node* createNode(float data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for(int i=0;i<n;i++){
        float h,w;
        printf("Enter height and weight of student %d: ",i+1);
        scanf("%f %f",&h,&w);
        float ratio = w/h;
        struct Node* newNode = createNode(ratio);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct Node* temp = head;
    float max_ratio = 0;
    int student_index = 0, max_index = 0;
    while(temp != NULL){
        if(temp->data > max_ratio){
            max_ratio = temp->data;
            max_index = student_index;
        }
        temp = temp->next;
        student_index++;
    }
    printf("Heighest weight/height ratio = %.2f (student %d)\n",max_ratio,max_index+1);

    return 0;
}