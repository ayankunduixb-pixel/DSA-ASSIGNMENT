// Given an integer array, print all sub arrays with zero-sum.

#include <stdio.h>

void printZeroSumSubarrays(int arr[],int n){
    int found = 0;
    
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter number of elements: ");
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printZeroSumSubarrays(arr, n);
    return 0;
}