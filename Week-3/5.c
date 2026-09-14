// 5. Insert an element at a specific position.
#include<stdio.h>
int main(){
    int n,pos,val;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[100];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter position to insert: ");
    scanf("%d",&pos);
    printf("Enter value to insert: ");
    scanf("%d",&val);
    for(int i=n;i>pos;i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    n++;
    printf("Updated Array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}