#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of coins: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter the coins:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int am;
    printf("Enter the amount: ");
    scanf("%d", &am);

    sort(a, n);

    printf("Sorted coins:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int *v = (int *)calloc(n, sizeof(int));

    int i = n - 1;
    while (am != 0 && i >= 0) {
        if (am >= a[i]) {
            v[i] = am / a[i];
            am = am % a[i];
        }
        i--;
    }

    printf("The vector solution is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(a);
    free(v);

    return 0;
}
