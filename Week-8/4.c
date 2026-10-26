// Write a program to search a number occurring odd number of times.

#include <stdio.h>

int main() {
    int n;

    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = 0;
    for(int i=0;i<n;i++){
        result = result ^ arr[i];
    }
    printf("Number occurring odd number of times : %d",result);
    return 0;
}