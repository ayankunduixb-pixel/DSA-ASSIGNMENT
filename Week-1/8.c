#include<stdio.h>
void reverse(int arr[],int start,int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotateLeft(int arr[],int n,int k){
    k=k%n;
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
}
void rotateRight(int arr[],int n,int k){
    k=k%n;
    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
}
int main(){
    int n,k;
    printf("Enter size of the array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d elements: \n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter K:");
    scanf("%d",&k);

     // Rotate left
    rotateLeft(arr, n, k);
    printf("Array after left rotation by %d:\n", k);
    for (int i = 0; i < n; i++){  
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Rotate right
    rotateRight(arr, n, k);
    printf("Array after right rotation by %d:\n", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}