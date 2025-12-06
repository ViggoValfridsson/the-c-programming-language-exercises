// Write a program to remove all comments from a C program. Don't forget to handle quoted string and character constants
// properly. C comments do not nest

// Todo need to handle character constants, \" escape sequence in strings, dangling slash not being printed 

#include <stdbool.h>
#include <stdio.h>

void skip_to_newline() {
    while (true) {
        char c = getchar();

        if (c == '\n') {
            putchar('\n');
            return;
        }
        if (c == EOF) {
            return;
        }
    }
}

void skip_to_multiline_close() {
    char last = 0;
    char current = 0;

    while (true) {
        current = getchar();

        if ((last == '*' && current == '/') || current == EOF) {
            return;
        }

        last = current;
    }
}

void print_buffer(char last, char current) {
}

int main() {
    bool is_in_string = false;
    bool is_multi_line = false;
    char last = 0;
    char current;

    while ((current = getchar()) != EOF) {
        is_in_string = is_in_string ? current != '"' : current == '"';

        if (is_in_string) {
            last = 0;
            putchar(current);
            continue;
        } else if (!is_in_string && last == '/' && current == '/') {
            skip_to_newline();
            last = 0;
            continue;
        } else if (!is_in_string && last == '/' && current == '*') {
            skip_to_multiline_close();
            last = 0;
            continue;
        }

        if (current != '/') {
            if (last == '/') {
                putchar(last);
            }

            putchar(current);
        }

        last = current;
    }
}
