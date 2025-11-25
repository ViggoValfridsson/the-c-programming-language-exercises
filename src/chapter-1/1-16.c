// Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input
// lines, and as much possible of the text

#include <stdio.h>

// Shortened limit to make it easier to test and demonstrate
#define MAX_LINE 30

// this function name conflicts with libc
int getline_2(char s[], int lim) {
    int character;
    int len = 0;

    while ((character = getchar()) != EOF && character != '\n') {
        if (len < lim - 1) {
            s[len] = character;
        } 

        len++;
    }

    if (character == '\n') {
        if (len < lim - 1)
            s[len] = character;  
        len++;                  
    }

    if (len < lim){
        s[len] = '\0';
    }
    else {
        s[lim - 1] = '\0';
    }

    return len;
}

void copy(char to[], char from[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}

int main() {
    int len;
    int max;
    char line[MAX_LINE];
    char longest[MAX_LINE];

    max = 0;

    while ((len = getline_2(line, MAX_LINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("Length %d. Full line unless overflowing: %s\n", max, longest);
    }

    return 0;
}
