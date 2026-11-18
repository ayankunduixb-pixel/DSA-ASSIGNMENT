#include <stdio.h>

void printZeroSumSubarrays(int arr[], int n) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == 0) {
                found = 1;
                printf("Subarray: ");

                for (int k = i; k <= j; k++) {
                    printf("%d ", arr[k]);
                }

                printf("\n");
            }
        }
    }

    if (!found) {
        printf("No zero-sum subarray found.\n");
    }
}

int main() {
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printZeroSumSubarrays(arr, n);

    return 0;
}