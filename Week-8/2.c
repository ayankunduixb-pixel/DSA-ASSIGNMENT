// Write a program to implement binary search.

#include <stdio.h>

int binarySearch(int arr[],int n,int target){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements (in sorted order): ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int target;
    printf("Enter the target: ");
    scanf("%d",&target);
    int result = binarySearch(arr,n,target);
    if(result != -1){
        printf("%d is found at index %d",target,result);
    }
    else{
        printf("%d is not found",target);
    }
    return 0;
}