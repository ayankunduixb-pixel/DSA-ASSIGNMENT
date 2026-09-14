#include<stdio.h>
int main(){
    int arr[100];
    int n;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    printf("Enter %d elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i] == arr[j]){
                for(int k=j;k<n-1;k++){
                    arr[k] = arr[k+1];
                }
                n--;
                j--;
            }
        }
    }
    // Print updated array
    printf("Array after removing duplicates: ");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}