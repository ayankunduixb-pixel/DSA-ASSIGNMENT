// Write a program to perform addition of two polynomials using linked list.
#include <stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int exp;
    struct Node* next;
};

struct Node *poly1 = NULL;
struct Node *poly2 = NULL;
struct Node *result = NULL;

struct Node* insert(struct Node* head,int coeff,int exp){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if(head == NULL){
        return newNode;
    }
    struct Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* addPoly(struct Node* p1, struct Node* p2){
    struct Node* res = NULL;
    while(p1 != NULL && p2 != NULL){
        if(p1->exp == p2->exp){
            res = insert(res,p1->coeff+p2->coeff,p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->exp > p2->exp){
            res = insert(res,p1->coeff,p1->exp);
            p1 = p1->next;
        }
        else{
            res = insert(res,p2->coeff,p2->exp);
            p2 = p2->next;
        }
    }
    while(p1 != NULL){
        res = insert(res,p1->coeff,p1->exp);
        p1 = p1->next;
    }
    while(p2 != NULL){
        res = insert(res,p2->coeff,p2->exp);
        p2 = p2->next;
    }
    return res;
}

void display(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d^%d",temp->coeff,temp->exp);

        if(temp->next != NULL){
            printf("+");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    /* Polynomial 1: 5x² + 4x + 2 */
    poly1 = insert(poly1, 5, 2);
    poly1 = insert(poly1, 4, 1);
    poly1 = insert(poly1, 2, 0);

    /* Polynomial 2: 3x² + 5x + 5 */
    poly2 = insert(poly2, 3, 2);
    poly2 = insert(poly2, 5, 1);
    poly2 = insert(poly2, 5, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    result = addPoly(poly1, poly2);

    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}