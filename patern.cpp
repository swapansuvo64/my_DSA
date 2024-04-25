#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            int isOnBorder = 0;

            // Check if the current position is on the border
            for (int k = 0; k < n; k++) {
                if (j == k || j == (2 * n - 2 - k) || i == k || i == (2 * n - 2 - k)) {
                    printf("%d ", n - k);
                    isOnBorder = 1;
                    break;
                }
            }

            // If not on the border, print the central value
            if (!isOnBorder) {
                printf("%d ", n);
            }
        }
        printf("\n");
    }

    return 0;
}
