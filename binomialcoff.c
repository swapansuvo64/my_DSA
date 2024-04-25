#include<stdio.h>

// Function to calculate binomial coefficient C(n, k) using dynamic programming
int binomialCoefficient(int n, int k) {
    int C[n+1][k+1];
    int i, j;
 
    // Calculate value of Binomial Coefficient in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k && j <= i; j++) {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previously stored values
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
 
    return C[n][k];
}

// Driver code
int main() {
    int n, k;
    printf("Enter the value of n and k (n choose k): ");
    scanf("%d %d", &n, &k);
    
    printf("C(%d, %d) = %d\n", n, k, binomialCoefficient(n, k));
    return 0;
}
