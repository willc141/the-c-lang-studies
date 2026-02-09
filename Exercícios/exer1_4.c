/*
Exercise 1−4. Write a program to print the 
corresponding Celsius to Fahrenheit table.
*/

#include <stdio.h>

int main() {
    float lower, upper, step;
    float fahrenheit, celsius;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("=== Celsius === Fahrenheit ===\n");
    
    while (celsius <= upper) {
        fahrenheit = (celsius * 9.0 / 5.0) + 32;
        printf("\t%3.0f\t%6.1f\n", celsius, fahrenheit);
        celsius = celsius + step;
    }
}