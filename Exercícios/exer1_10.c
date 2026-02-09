#include <stdio.h>

/*
Exercise 1−10. Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.
*/

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            while ((c = getchar()) == '\t');
            putchar('\\');
            putchar('\t');
        }

        if (c == '\b') {
            while ((c = getchar()) == '\b');
            putchar('\\');
            putchar('\b');
        }

        if (c == '\\') {
            while ((c = getchar()) == '\\');
            putchar('\\');
            putchar('\\');
        }

        putchar(c);
    }
}
