// Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input
// lines, and as much possible of the text

#include <stdio.h>

// Shortened limit to make it easier to test and demonstrate
#define MAX_LINE 1000
#define MIN_LINE 80

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

int main() {
    int len;
    char line[MAX_LINE];

    while ((len = getline_2(line, MAX_LINE)) > 0) {
        if (len > MIN_LINE) {
            printf("Line longer than 80 chars: %s", line);
        }
    }

    return 0;
}
