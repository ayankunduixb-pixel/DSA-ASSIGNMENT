#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    printf("Enter a phrase: ");
    scanf("%s",str);

    printf("Abbreviation: ");
    for (int i = 0; i < strlen(str); i++) {
        // Print first letter of each word
        if (i == 0 || str[i-1] == ' ') {
            if (str[i] != ' ' && str[i] != '\n')
                printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}