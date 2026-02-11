#include <stdio.h>

/* Exercise 1−14. Write a program to print a histogram of the frequencies of different characters in its input. */

#define ASCII_SIZE 256

int main()
{
    int contagens[ASCII_SIZE];
    int i, j, c;

    i = j = 0;
    
    /* inicializa o array com 0's */
    for (int i = 0; i < ASCII_SIZE; ++i) {
        contagens[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        ++contagens[c];
    }

    /* exibe o histograma */
    for (i = 0; i < ASCII_SIZE; ++i) {
        if (contagens[i] > 0) {
            printf("\n%c: ", (char)i);
            for (j = 0; j < contagens[i]; ++j) {
                printf("*");
            }
        }
    }
    
    printf("\n");

    return 0;
}