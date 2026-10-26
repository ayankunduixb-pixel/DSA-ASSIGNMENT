// Write a program to implement linear search.

#include <stdio.h>

int linearSearch(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int target;
    printf("Enter the target: ");
    scanf("%d",&target);
    int result = linearSearch(arr,n,target);
    if(result != -1){
        printf("%d is found at index %d",target,result);
    }
    else{
        printf("%d is not found",target);
    }
    return 0;
}