#include <stdio.h>
void merge(int a[], int left, int right, int mid) {
    int n1 = (mid - left) + 1;
    int n2 = right - mid;
    int a1[n1], a2[n2], i, j, k;
    
    for (i = 0; i < n1; i++) {
        a1[i] = a[left + i];
    }
    for (j = 0; j < n2; j++) {
        a2[j] = a[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (a1[i] <= a2[j]) {
            a[k] = a1[i];
            i++;
        } else {
            a[k] = a2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = a1[i];
        i++;
        k++;
    } 
    while (j < n2) {
        a[k] = a2[j];
        j++;
        k++;
    }
}
void mergesort(int a[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, r);
        merge(a, l, r, mid);
    }
}

int main() {
    int a[5], i, l = 0, r = 4;
    printf("Enter the array:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("Original array:\n");
    for (i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    
    mergesort(a, l, r);
    
    printf("Sorted array:\n");
    for (i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    
    return 0;
}
