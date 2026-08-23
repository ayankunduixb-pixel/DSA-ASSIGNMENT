#include<stdio.h>
int main(){
    int rows,cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int r1,r2;
    printf("Enter two row indices to interchange: ");
    scanf("%d %d",&r1,&r2);
    for(int j = 0;j<cols;j++){
        int temp = matrix[r1][cols];
        matrix[r1][cols] = matrix[r2][cols];
        matrix[r2][cols] = temp;
    }
    printf("Matrix after interchanging rows:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}