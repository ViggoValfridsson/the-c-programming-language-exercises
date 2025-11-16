#include <stdio.h>

int main() {
    float fahr = 0;
    int upper = 300;
    int step = 20;

    printf("%3s %6s\n", "f", "c");

    while (fahr <= upper) {
        float celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);

        fahr += step;
    }

    return 0;
}
