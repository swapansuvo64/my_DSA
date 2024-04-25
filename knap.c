#include<stdio.h>
#include<stdlib.h>

void sort(double arr[], int n) {
    int i, j;
    double temp;
    for (i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, c, i;
    printf("Enter the size of input: ");
    scanf("%d", &n);

    printf("Enter the capacity: ");
    scanf("%d", &c);

    int *p = (int *)malloc(n * sizeof(int));
    int *w = (int *)malloc(n * sizeof(int));
    double *v = (double *)malloc(n * sizeof(double));
    int *ob = (int *)malloc(n * sizeof(int));

    printf("Enter the profit and weight: \n");
    for (i = 0; i < n; i++) {
        printf("%d) Object profit and weight: ", i + 1);
        scanf("%d %d", &p[i], &w[i]);
        ob[i] = i;
        v[i] = (double)p[i] / w[i];
    }

    sort(v, n);

    int profit = 0;
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i] == (double)p[j] / w[j]) {
                if (c > w[j]) {
                    c -= w[j];
                    profit += p[j];
                } else {
                    profit += c * ((double)p[j] / w[j]);
                    c = 0;
                }
            }
        }
    }

    printf("The maximum profit is: %d\n", profit);

    free(p);
    free(w);
    free(v);
    free(ob);

    return 0;
}
