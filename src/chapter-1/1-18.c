// Write a program to remove trailing blanks and tabs from each line of input, and to entirely delete blank lines
#include <stdio.h>

#define MAX_LINE 1000

int remove_trailing_whitespace(char s[], int len) {
    for (int i = len - 1; i >= 0; i--) {
        char current_char = s[i];

        if (current_char == ' ' || current_char == '\t' || current_char == '\n') {
            s[i] = '\0';
        } else {
            return i + 1;
        }
    }

    return 0;
}

int get_and_trim_line(char s[], int lim) {
    int character;
    int len = 0;

    while ((character = getchar()) != EOF && character != '\n' && len < lim - 1) {
        s[len] = character;
        len++;
    }

    int trimmed_len = remove_trailing_whitespace(s, len);

    if (trimmed_len == 0 && len != 0) {
        return get_and_trim_line(s, lim);
    }

    s[trimmed_len] = '\0';
    return trimmed_len;
}

int main() {
    int len;
    char line[MAX_LINE];

    while ((len = get_and_trim_line(line, MAX_LINE)) > 0) {
        // Custom print to clearly show if line contains trailing whitespace
        for (int i = 0; i < len; i++) {
            if (line[i] == ' ') {
                printf("%%20");
            } else if (line[i] == '\t') {
                printf("\\t");
            } else {
                putchar(line[i]);
            }
        }
        putchar('\n');
    }

    return 0;
}
