
/*
Exercise 1−3. Modify the temperature conversion program to print a heading above the table
*/

#include <stdio.h>

int main() {
    float lower, upper, step;
    float fahrenheit, celsius;

    lower = 0;
    upper = 300;
    step = 20;

    fahrenheit = lower;
    printf("=== Fahrenheit === Celsius ===\n");

    while (fahrenheit <= upper) {
        celsius = (5.0 / 9.0) * (fahrenheit - 32);
        printf("\t%3.0f\t%6.1f\n", fahrenheit, celsius);
        fahrenheit += step;
    }
}
