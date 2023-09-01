#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void generate_permutations(char *word, int start, int end) {
    if (start == end) {
        printf("%s\n", word);
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&word[start], &word[i]);
        generate_permutations(word, start + 1, end);
        swap(&word[start], &word[i]); // Backtrack
    }
}

int main() {
    char word[100];
    printf("Enter a word: ");
    scanf("%s", word);

    int length = strlen(word);
    generate_permutations(word, 0, length - 1);

    return 0;
}
