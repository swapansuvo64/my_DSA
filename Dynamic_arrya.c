#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare a pointer to int
    int *dynamicArray;

    // Get the size of the array from the user or any other source
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    dynamicArray = (int *)malloc(size * sizeof(int));

    // Check if allocation was successful
    if (dynamicArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit with an error code
    }

    // Initialize the array elements
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = i * 2; // You can initialize with any values you want
    }

    // Access and print the array elements
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);
    }

    // Don't forget to free the allocated memory when done
    free(dynamicArray);

    return 0; // Exit successfully
}
