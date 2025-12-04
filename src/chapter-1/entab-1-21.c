// Write a program "entab" that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same
// spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop,
// which should be given preference.

#include <stdbool.h>
#include <stdio.h>

#define TAB_SIZE 8

int emit_tabs(int current_col, int target_col, int tab_size) {
    while (true) {
        int next_stop = current_col + tab_size - (current_col % tab_size);

        if (next_stop > target_col) {
            break;
        } else {
            // Print escaped tab to make output easier to read, should actually be putchar('\t')
            printf("\\t");
            current_col = next_stop;
        }
    }

    return current_col;
}

int emit_spaces(int current_col, int target_col) {
    while (current_col < target_col) {
        putchar(' ');
        current_col++;
    }

    return current_col;
}

// Replaces spaces with minimum amount of tabs and spaces needed to achieve the same spacing. 
// If a single tab or blank would suffice, we will always print tab
int entab_spaces(int current_col, int tab_size) {
    // One space was already seen before calling this method so we account for that
    int space_count = 1;
    int c;

    while ((c = getchar()) == ' ') {
        space_count++;
    }

    // return the non-space so main can see it
    if (c != EOF) {
        ungetc(c, stdin);
    }

    int target_col = current_col + space_count;

    current_col = emit_tabs(current_col, target_col, tab_size);
    current_col = emit_spaces(current_col, target_col);

    return current_col;
}

int main(void) {
    char character;
    int col = 0;

    while ((character = getchar()) != EOF) {
        int current_space_count = 0;

        if (character == ' ') {
            col = entab_spaces(col, TAB_SIZE);
        } else {
            putchar(character);
            col++;

            if (character == '\n') {
                col = 0;
            }
        }
    }
}
