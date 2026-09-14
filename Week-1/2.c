#include <stdio.h>

int main() {
    int n = 5;
    // Upper half
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++)
            printf(" ");
        for (int j = n; j > n - i - 1; j--)
            printf("%d", j);
        for (int j = n - i + 1; j <= n; j++)
            printf("%d", j);
        printf("\n");
    }
    // Lower half
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++)
            printf(" ");
        for (int j = n; j > n - i - 1; j--)
            printf("%d", j);
        for (int j = n - i + 1; j <= n; j++)
            printf("%d", j);
        printf("\n");
    }
    return 0;
}
