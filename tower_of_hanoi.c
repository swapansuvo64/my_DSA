#include <stdio.h>

// Function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n-1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n-1, auxiliary, source, destination);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Steps to solve the Tower of Hanoi problem with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');  // 'A' is the source rod, 'B' is the auxiliary rod, 'C' is the destination rod
    return 0;
}
