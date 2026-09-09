// . Write a C program to create an 2D array using the array of pointers concept 
// and calculate row-wise sum. Also, print the 2D array using pointers to array 
// concept.

#include <stdio.h>
#include<stdlib.h>

int main() {
    int rows,cols;

    printf("Enter rows and columns: ");
    scanf("%d %d",&rows,&cols);

    // Array of pointers
    int **arr = (int **)malloc(rows * sizeof(int *));

    // Allocate memory for each row
    for(int i=0;i<rows;i++){
        arr[i] = (int *)malloc(cols* sizeof(int));
    }
    printf("Enter elemnts:\n");

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Row-wise sum: \n");

    for(int i=0 ; i < rows ; i++){
        int sum = 0;
        for(int j = 0 ; j < cols ; j++){
            sum += arr[i][j];
        }
        printf("Row %d = %d\n",i+1,sum);
    }

    printf("\n2D Array:\n");

    int (*ptr)[cols];

    for (int i = 0; i < rows; i++) {
        ptr = (int (*)[cols])arr[i];

        for (int j = 0; j < cols; j++) {
            printf("%d ", ptr[0][j]);
        }

        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }

    free(arr);

    return 0;
}