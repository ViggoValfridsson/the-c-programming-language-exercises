#include <stdio.h>

int main() {
    int character;
    long long count = 0;

    while ((character = getchar()) != EOF) {
        if (character == '\n' || character == '\t' || character == ' '){
            count++;
        }
    }

    printf("%lld\n", count);

    return 0;
}
