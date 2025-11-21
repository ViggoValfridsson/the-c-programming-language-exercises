// Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the
// bars horizontal; a verical orientation is more challenging

// This file contains the vertical solution, the horizontal solution can be found in 1-13-horizontal.c

// I decided to start splitting up the main function, as this example was quite a lot larger than previous exercises

#include <stdbool.h>
#include <stdio.h>

#define MAX_WORD_COUNT 1024

int read_word_lengths(int *word_lengths, int max_words) {
    int word_index = 0;
    bool is_last_space = true;
    int character;

    while ((character = getchar()) != EOF && word_index < max_words) {
        bool is_current_space = character == ' ' || character == '\t' || character == '\n';

        if (is_current_space && !is_last_space) {
            word_index++;
        } else if (!is_current_space) {
            word_lengths[word_index]++;
        }

        is_last_space = is_current_space;
    }

    // After loop, account for last word if it didn't end with space
    if (!is_last_space) {
        word_index++;
    }

    return word_index;
}

int find_max_word_len(int *word_lengths, int word_index) {
    int longest_word_length = 0;

    for (int i = 0; i < word_index; i++) {
        int current_length = word_lengths[i];

        if (current_length > longest_word_length) {
            longest_word_length = current_length;
        }
    }

    return longest_word_length;
}

void print_histogram_bars(int longest_word_length, int *word_lengths, int word_count) {
    for (int row = longest_word_length; row > 0; row--) {
        for (int column = 0; column < word_count; column++) {
            printf(word_lengths[column] >= row ? "|||| " : "     ");
        }
        putchar('\n');
    }
}

void print_histogram_header(int word_count) {
    for (int i = 0; i < word_count; i++) {
        printf("%4d ", i + 1);
    }

    putchar('\n');
}

int main() {
    int word_lengths[MAX_WORD_COUNT] = {0};

    int word_count = read_word_lengths(word_lengths, MAX_WORD_COUNT);
    int longest_word_length = find_max_word_len(word_lengths, word_count);

    print_histogram_bars(longest_word_length, word_lengths, word_count);
    print_histogram_header(word_count);

    return 0;
}
