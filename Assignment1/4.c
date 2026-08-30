#include<stdio.h>
int main(){
    int arr[100];
    int n;
    printf("Enter number of elements:");
    scanf("%d", &n);

    printf("Enter %d elements: \n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    // Input position and value
    int pos,val;
    printf("Enter the position: ");
    scanf("%d", &pos);
    printf("Enter the value: ");
    scanf("%d",&val);

    // Shift Elements to the right
    for(int i=n;i>pos;i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    n++;

    // print the updated array
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }

    return 0;
}