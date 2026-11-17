// Check if a sub array with 0 sum exists or not.

#include <stdio.h>

int subArrayExists(int arr[],int n){
    for(int i = 0;i<n;i++){
        int sum = 0;
        for(int j = 0;j<n;j++){
            sum += arr[j];

            if(sum == 0){
                return 1;
            }
        }
    }
    return 0;
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

    if(subArrayExists(arr,n)){
        printf("Yes,subarray with sum 0 exist");
    }
    else{
        printf("No,subarray with sum 0 deosn't exist");
    }
    return 0;
}