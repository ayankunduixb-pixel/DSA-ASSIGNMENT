#include <stdio.h>

int main() {
    int arr[25];
    int pos = 0, neg = 0, even = 0, odd = 0;

    printf("Enter 25 numbers:\n");
    for (int i = 0; i < 25; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] > 0)
            pos++;
        else if (arr[i] < 0)
            neg++;

        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("Positive numbers: %d\n", pos);
    printf("Negative numbers: %d\n", neg);
    printf("Even numbers: %d\n", even);
    printf("Odd numbers: %d\n", odd);

    return 0;
}
