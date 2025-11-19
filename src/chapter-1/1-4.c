#include <stdio.h>

// Write a program to print the corresponding Celcius to Fahrenheit table
int main() {
    float celsius = 0;
    int upper = 300;
    int step = 20;

    printf("%3s %6s\n", "c", "f");

    while (celsius <= upper) {
        float fahr = (celsius * (9.0 / 5.0)) + 32.0;
        printf("%3.0f %6.0f\n", celsius, fahr);

        celsius += step;
    }

    return 0;
}
