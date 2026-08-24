#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s",str);

    int n = strlen(str);
    int flag = 1;

    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("The string is a Palindrome\n");
    else
        printf("The string is Not a Palindrome\n");

    return 0;
}
