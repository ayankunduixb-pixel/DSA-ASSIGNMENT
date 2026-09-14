#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxi = INT_MIN;
    int mini = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxi)
            maxi = arr[i];
        if (arr[i] < mini)
            mini = arr[i];
    }

    printf("Maximum value in array: %d\n", maxi);
    printf("Minimum value in array: %d\n", mini);

    return 0;
}
