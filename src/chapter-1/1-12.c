#include <stdbool.h>
#include <stdio.h>

// Write a program that prints its input one word per line
int main() {
    int character;
    bool is_last_space = false;

    while ((character = getchar()) != EOF) {
        bool is_current_space = character == ' ' || character == '\n' || character == '\t';

        if (is_current_space && !is_last_space) {
            putchar('\n');
            is_last_space = true;
        } else if (!is_current_space) {
            is_last_space = false;
            putchar(character);
        }
    }

    return 0;
}
