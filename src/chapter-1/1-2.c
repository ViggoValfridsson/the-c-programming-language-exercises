#include <stdio.h>

// Experiment to find out what happens when printf's argument string contains \c, where c is some character not listed above (not a real escape sequence)
int main() {
    printf("hello, world\c\n");
}
