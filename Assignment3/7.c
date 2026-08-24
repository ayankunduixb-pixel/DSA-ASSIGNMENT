// Write a program to reverse a string.
#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s",str);

    int n = strlen(str);
    for(int i=0;i<n/2;i++){
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
    printf("Reversed string: %s\n",str);
    return 0;
}