#include <stdio.h>

int main() {
    int character;
    int last = 0;

    while ((character = getchar()) != EOF) {
        if (character != ' ' || last != ' ') {
            putchar(character);
        }
        last = character;
    }

    return 0;
}
