// Find maximum length sub array having an equal number of 0’s and 1’s
#include <stdio.h>

void maxEqual01Subarray(int arr[], int n) {
    int maxLen = 0, start = -1, end = -1;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {

            if (arr[j] == 0)
                sum += -1;
            else
                sum += 1;

            if (sum == 0) {
                int len = j - i + 1;

                if (len > maxLen) {
                    maxLen = len;
                    start = i;
                    end = j;
                }
            }
        }
    }

    if (start == -1) {
        printf("No such subarray exists.\n");
        return;
    }

    printf("Maximum Length = %d\n", maxLen);
    printf("Subarray: ");

    for (int i = start; i <= end; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main() {
    int arr[] = {1, 0, 1, 1, 1, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    maxEqual01Subarray(arr, n);

    return 0;
}