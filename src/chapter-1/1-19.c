// Write a function reverse that reverses the character string s. Use it to write a program that reverses its input a
// line at a time.

#include <stdio.h>

#define MAX_LINE 1000

void reverse(char s[], int len) {
    for (int i = 0; i < len / 2; i++) {
        int reverse_index = len - i - 1;
        char temp = s[i];
        s[i] = s[reverse_index];
        s[reverse_index] = temp;
    }
}

int get_reverse_line(char s[], int lim) {
    int character;
    int len = 0;

    while ((character = getchar()) != EOF && character != '\n') {
        if (len < lim - 1) {
            s[len] = character;
        }

        len++;
    }

    if (len < lim) {
        s[len] = '\0';
    } else {
        s[lim - 1] = '\0';
    }

    reverse(s, len);

    return len;
}

int main() {
    int len;
    char line[MAX_LINE];

    while ((len = get_reverse_line(line, MAX_LINE)) > 0) {
        printf("Reversed: %s\n", line);
    }

    return 0;
}
