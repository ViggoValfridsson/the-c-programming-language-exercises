#include <stdio.h>

int main() {
    int comparison_result = getchar() != EOF;

    // This is obviously the same as !comparison_result || comparison_result but to me the question seems to ask me to explicitly check against 0 or 1 not true/false
    // This statement will always be true regardless of input
    if (comparison_result == 0 || comparison_result == 1) {
        printf("Result of comparison is either 0 or 1\n");
    } else {
        printf("Result of comparison is not 0 or 1\n");
    }

    return 0;
}
