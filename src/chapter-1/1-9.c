#include <stdio.h>

// Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank
int main() {
    int character;
    int last = 0;

    while ((character = getchar()) != EOF) {
        if (character != ' ' || last != ' ') {
            putchar(character);
        }
        last = character;
    }

    return 0;
}
