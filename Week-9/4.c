// Given an integer array, find the maximum length sub array having a given sum.
#include <stdio.h>

void maxLenSubarray(int arr[], int n, int target) {
    int maxLen = 0;
    int start = -1, end = -1;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == target) {
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
        printf("No subarray found.\n");
    } else {
        printf("Maximum Length = %d\n", maxLen);
        printf("Subarray: ");

        for (int i = start; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int arr[] = {10, 5, 2, 7, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    maxLenSubarray(arr, n, target);

    return 0;
}