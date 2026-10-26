// Given an unsorted integer array, find a pair with the given sum in it.

#include <stdio.h>


int main() {
    int n,sum;
    int i,j,found = 0;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the elements: ");
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter the required Sum: ");
    scanf("%d",&sum);

    for(int i = 0;i<n-1;i++){
        for(int j = i+1; j<n;j++){
            if(arr[i] + arr[j] == sum){
                printf("Pair found: (%d,%d)\n",arr[i],arr[j]);
                found = 1;
            }
        }
    }

    if(!found){
        printf("No Pair found.\n");
    }
    
    return 0;
}