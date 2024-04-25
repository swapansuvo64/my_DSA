#include <stdio.h>

// Function to find the maximum and minimum elements in an array using divide and conquer
void maxMin(int arr[], int low, int high, int *max, int *min) {
    int mid, max1, min1, max2, min2;

    // Base case: When there is only one element
    if (low == high) {
        *max = arr[low];
        *min = arr[low];
        return;
    }

    // When there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    // Divide the array into two halves and recursively find the maximum and minimum in each half
    mid = (low + high) / 2;
    maxMin(arr, low, mid, &max1, &min1);
    maxMin(arr, mid + 1, high, &max2, &min2);

    // Compare the maximums and minimums of the two halves
    if (max1 > max2)
        *max = max1;
    else
        *max = max2;
    if (min1 < min2)
        *min = min1;
    else
        *min = min2;
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max, min;
    maxMin(arr, 0, n - 1, &max, &min);
    printf("Maximum element in the array: %d\n", max);
    printf("Minimum element in the array: %d\n", min);

    return 0;
}
