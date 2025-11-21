// Write a program to print a histogram of the frequencies of different charaters in its input.

#include <stdbool.h>
#include <stdio.h>

#define ASCII_CHARACTER_COUNT 128

void read_character_occurrences(int *character_occurrences, int len) {
    int character;

    while ((character = getchar()) != EOF) {
        if (character < len) {
            character_occurrences[character]++;
        }
    }
}

void print_histogram(int *character_occurrences, int len) {
    for (int i = 0; i < len; i++) {
        int occurences = character_occurrences[i];

        if (occurences == 0) {
            continue;
        }

        // Newline offsets 
        // One should probably add a case like this for all whitespace chars
        if (i == '\n') {
            printf("\\n: ");
        } else {
            printf("%c: ", i);
        }

        for (int j = 0; j < occurences; j++) {
            putchar('-');
        }

        putchar('\n');
    }
}

int main() {
    int character_occurrences[ASCII_CHARACTER_COUNT] = {0};

    read_character_occurrences(character_occurrences, ASCII_CHARACTER_COUNT);
    print_histogram(character_occurrences, ASCII_CHARACTER_COUNT);

    return 0;
}
