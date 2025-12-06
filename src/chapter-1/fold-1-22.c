// Write a  program to "fold" long input lines into two or more shorter lines after the last non-blank character that
// occurs before the n-th column of input. Make sure your program doess something intelligent with very long lines, and
// if there are no blanks or tabs before the specified column.

#include <stdio.h>

#define MAX_LINE_WIDTH 100

int index_of_last_whitespace(char line[], int len) {
    for (int i = len - 1; i >= 0; i--) {
        char current = line[i];

        if (current == ' ' || current == '\t') {
            return i;
        }
    }

    return -1;
}

void print_line(char line[], int len) {
    for (int i = 0; i < len; i++) {
        putchar(line[i]);
    }
}

int copy_remainder(char line[], int start, int end) {
    int i;

    for (i = start; i < end; i++) {
        if (line[i] == '\0') {
            break;
        }

        line[i - start] = line[i];
    }

    return i - start;
}

int main() {
    int current_col = 0;
    // +1 to account for null terminator
    char line[MAX_LINE_WIDTH + 1] = {0};
    char c;

    while ((c = getchar()) != EOF) {
        line[current_col] = c;
        current_col++;

        if (c == '\n') {
            print_line(line, current_col);
            current_col = 0;
            continue;
        }

        if (current_col == MAX_LINE_WIDTH) {
            int last_whitespace = index_of_last_whitespace(line, MAX_LINE_WIDTH);

            if (last_whitespace == -1) {
                print_line(line, MAX_LINE_WIDTH);
                putchar('\n');
                current_col = 0;
            } else {
                print_line(line, last_whitespace);
                putchar('\n');
                current_col = copy_remainder(line, last_whitespace + 1, MAX_LINE_WIDTH);
            }
        }
    }

    print_line(line, current_col);

    return 0;
}
