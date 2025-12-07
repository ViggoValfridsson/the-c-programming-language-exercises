// Write a program to remove all comments from a C program. Don't forget to handle quoted string and character constants
// properly. C comments do not nest

// Todo need to \" escape sequence in strings, dangling slash not being printed

#include <stdbool.h>
#include <stdio.h>

int is_between_chars(char current, char target, bool is_already_inside) {
    return is_already_inside ? current != target : current == target;
}

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

int main() {
    bool is_string = false;
    bool is_char_constant = false;
    bool is_multi_line = false;
    char last = 0;
    char current;

    while ((current = getchar()) != EOF) {
        is_string = is_between_chars(current, '"', is_string);
        is_char_constant = is_between_chars(current, '\'', is_char_constant);

        if (is_string || is_char_constant) {
            last = 0;
            putchar(current);
            continue;
        } else if (last == '/' && current == '/') {
            skip_to_newline();
            last = 0;
            continue;
        } else if (last == '/' && current == '*') {
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
