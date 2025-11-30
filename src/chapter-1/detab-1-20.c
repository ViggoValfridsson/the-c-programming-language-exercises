// Write a program "detab" that replaces tabs in the input with the proper number of blanks to space to the next tab
// stop. Assume a fixed set of tab stops say every n columns. Should n be a variable or a symbolic parameter?

#include <stdbool.h>
#include <stdio.h>

#define TAB_SIZE 8

int spaces_to_next_stop(int column, int tab_size) {
    int stop = tab_size;

    while (true) {
        if (column < stop) {
            return stop - column;
        } else {
            stop += tab_size;
        }
    }
}

int main(void) {
    char character;
    int column = 0;

    while ((character = getchar()) != EOF) {
        if (character == '\t') {
            int next_stop = spaces_to_next_stop(column, TAB_SIZE);

            for (int i = 0; i < next_stop; i++) {
                putchar(' ');
                column++;
            }
        } else {
            putchar(character);
            column++;

            if (character == '\n') {
                column = 0;
            }
        }
    }
}
