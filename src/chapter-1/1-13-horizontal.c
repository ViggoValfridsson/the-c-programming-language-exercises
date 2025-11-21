// Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the
// bars horizontal; a verical orientation is more challenging

// This file contains the horizontal solution, the vertical solution can be found in 1-13-vertical.c

#include <stdbool.h>
#include <stdio.h>

#define MAX_WORD_COUNT 1024

int main() {
    int word_lengths[MAX_WORD_COUNT] = {0};
    int word_index = 0;
    bool is_last_space = true;
    int character;

    while ((character = getchar()) != EOF && word_index < MAX_WORD_COUNT) {
        bool is_current_space = character == ' ' || character == '\t' || character == '\n';
        if (is_current_space && !is_last_space) {
            is_last_space = true;
            word_index++;
        } else if (!is_current_space) {
            is_last_space = false;
            word_lengths[word_index]++;
        } else {
            is_last_space = is_current_space;
        }
    }

    // After loop, account for last word if it didn't end with space
    if (!is_last_space) {
        word_index++;
    }

    for (int i = 0; i < word_index; i++) {
        printf("word %d: ", i + 1);

        for (int j = 0; j < word_lengths[i]; j++) {
            putchar('-');
        }

        putchar('\n');
    }

    return 0;
}
