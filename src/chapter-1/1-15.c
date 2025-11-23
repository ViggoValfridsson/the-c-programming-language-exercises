#include <stdio.h>

// Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.

float convert_to_celsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}

int main() {
    float fahr = 0;
    int upper = 300;
    int step = 20;

    printf("%3s %6s\n", "f", "c");

    while (fahr <= upper) {
        float celsius = convert_to_celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);

        fahr += step;
    }

    return 0;
}
