#include <stdio.h>

int main() {
    char sentence[100]; // Adjust the array size as needed

    printf("Enter a sentence: ");
    
    // Consume the newline character from the previous input
    scanf("\n");
    
    // Read the sentence
    scanf("%[^\n]%*c", sentence);

    printf("You entered: %s\n", sentence);

    return 0;
}
