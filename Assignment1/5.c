#include<stdio.h>
int main(){
    int arr[100];
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements: \n",n);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int choice,pos,val;
    printf("Delete by:\n 1.index \n 2.value \n Enter choice: ");
    scanf("%d", &choice);
    if(choice == 1){
        printf("Enter index: ");
        scanf("%d",&pos);
        if(pos >= 0 && pos < n){
            for(int i=pos;i<n-1;i++){
                arr[i] = arr[i+1];
            }
            n--;
        }
        else{
            printf("Invalid index");
        }
    }
    else if(choice == 2){
        printf("Enter value to delete:");
        scanf("%d",&val);
        int found = -1;
        for(int i=0;i<n;i++){
            if(arr[i] == val){
                found = i;
                break;
            }
        }
        if(found != -1){
            for(int i=found;i<n-1;i++){
                arr[i] = arr[i+1];
            }
            n--;
        }
        else{
            printf("Value not found!\n");
        }
    }

    // Print the updated array
    printf("Updated array: ");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}