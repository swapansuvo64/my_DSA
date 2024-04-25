#include<stdio.h>
#include<stdlib.h>

struct job {
    int p; // profit
    int w; // weight
};

void sort(struct job arr[], int n) {
    int i, j;
    struct job temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].p < arr[j + 1].p) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    
    // Allocate memory for array of jobs
    struct job *j = (struct job *)malloc(n * sizeof(struct job));
    if (j == NULL) {
        printf("Memory allocation failed!\n");
        return -1; // Exit with error code
    }

    // Input profits and weights for each job
    printf("Enter the profits and weights for each job:\n");
    for(int i = 0; i < n; i++) {
        printf("job[%d]---> profit[%d], weight[%d]= \t",i,i,i);
        scanf("%d %d",&j[i].p,&j[i].w);
    }
    
    // Sort jobs by profit in descending order
    sort(j, n);
    
    // Display sorted jobs
    printf("\nSorted Jobs:\n");
    for(int i = 0; i < n; i++) {
        printf("Job[%d]---> profit[%d], weight[%d]\n", i, j[i].p, j[i].w);
    }
    
    // Find the maximum deadline
    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        if (j[i].w > max_deadline) {
            max_deadline = j[i].w;
        }
    }
    
    // Allocate memory for storing selected jobs
    int *selected_jobs = (int *)malloc(max_deadline * sizeof(int));
    if (selected_jobs == NULL) {
        printf("Memory allocation failed!\n");
        free(j);
        return -1; // Exit with error code
    }
    
    // Initialize selected jobs array
    for (int i = 0; i < max_deadline; i++) {
        selected_jobs[i] = -1; // Indicates no job selected
    }
    
    // Greedily select jobs with the highest profit and fit them into the nearest available deadline
    int total_profit = 0;
    for (int i = 0; i < n; i++) {
        for (int d = j[i].w - 1; d >= 0; d--) {
            if (selected_jobs[d] == -1) {
                selected_jobs[d] = i; // Select job i for deadline d
                total_profit += j[i].p; // Add profit of selected job to total profit
                break;
            }
        }
    }
    
    // Display selected jobs
    printf("\nSelected Jobs:\n");
    for (int i = 0; i < max_deadline; i++) {
        if (selected_jobs[i] != -1) {
            printf("Job[%d]---> profit[%d], weight[%d]\n", selected_jobs[i], j[selected_jobs[i]].p, j[selected_jobs[i]].w);
        }
    }
    
    // Display total profit
    printf("The total profit will be: %d\n", total_profit);

    // Free dynamically allocated memory
    free(j);
    free(selected_jobs);
    
    return 0;
}
