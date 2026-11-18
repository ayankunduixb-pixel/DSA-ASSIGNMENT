// Write a program to check whether number of opening ‘(‘ & closing ‘)’ parenthesis are equal
// or not.

#include <stdio.h>
#include<string.h>

int main() {
    char str[100];
    int open = 0,close = 0;
    printf("Enter an expression: ");
    scanf("%s",str);

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '(')
            open++;
        else if(str[i] == ')')
            close++;
    }

    printf("Opening parentheses = %d\n", open);
    printf("Closing parentheses = %d\n", close);

    if(open == close)
        printf("Number of parentheses are equal.\n");
    else
        printf("Number of parentheses are not equal.\n");

    return 0;
}