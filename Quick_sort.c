#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int pi = partition(a, lb, ub);
        quickSort(a, lb, pi - 1);
        quickSort(a, pi + 1, ub);
    }
}

int main() {
    int arr[100];
    printf("Enter 5 elements:\n");
    
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, 4);

    printf("\nSorted array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
