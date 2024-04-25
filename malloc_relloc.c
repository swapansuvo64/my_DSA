#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dynamicArray;

    // Allocate memory for an array of 5 integers
    dynamicArray = (int *)malloc(5 * sizeof(int));

    if (dynamicArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the array elements
    for (int i = 0; i < 5; i++) {
        dynamicArray[i] = i * 2;
    }

    // Print the array elements
    printf("Array elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Resize the array to accommodate 8 integers
    dynamicArray = (int *)realloc(dynamicArray, 8 * sizeof(int));

    if (dynamicArray == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        return 1;
    }

    // Initialize the new elements
    for (int i = 5; i < 8; i++) {
        dynamicArray[i] = i * 2;
    }

    // Print the updated array elements
    printf("Updated array elements: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(dynamicArray);

    return 0;
}
