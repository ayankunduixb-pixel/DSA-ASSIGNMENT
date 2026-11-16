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