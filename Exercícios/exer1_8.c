#include <stdio.h>

/*
Exercise 1−8. Write a program to count blanks, tabs, and newlines.
*/

int main()
{
    int c;
    int blanksCounter, tabsCounter, newLineCounter;

    blanksCounter = 0
    tabsCounter = 0;
    newLineCounter = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanksCounter;

        if (c == '\t')
            ++tabsCounter;

        if (c == '\n')
            ++newLineCounter;
    }

    printf("Blanks: %d\n", blanksCounter);
    printf("Tabs: %d\n", tabsCounter);
    printf("New Lines: %d\n", newLineCounter);

}
