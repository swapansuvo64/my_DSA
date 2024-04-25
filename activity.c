#include<stdio.h>
#include<stdlib.h>

struct ac {
    int s;
    int f;
};

void sort(struct ac arr[], int n) {
    int i, j;
    struct ac temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].f > arr[j + 1].f) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    
    struct ac *j = (struct ac *)malloc(n * sizeof(struct ac));

    if (j == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    printf("Enter the start and finish times for each activity:\n");
    for(int i = 0; i < n; i++) {
        printf("activity[%d]---> start[%d], finish[%d]= \t", i, i, i);
        scanf("%d %d", &j[i].s, &j[i].f);
    }
    
    sort(j, n);

    printf("\nThe selected activities are:\n");

    // Select the first activity
    printf("{%d, %d} ", j[0].s, j[0].f);

    // Initialize the index of the last selected activity
    int last_selected = 0;

    // Iterate through the remaining activities
    for (int i = 1; i < n; i++) {
        // If the start time of the current activity is after the finish time of the last selected activity
        if (j[i].s >= j[last_selected].f) {
            // Select the current activity
            printf("{%d, %d} ", j[i].s, j[i].f);
            // Update the index of the last selected activity
            last_selected = i;
        }
    }
    
    // Free dynamically allocated memory
    free(j);

    return 0;
}
