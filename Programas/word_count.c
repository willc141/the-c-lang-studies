#include <stdio.h>

/* conta linhas, palavras e caracteres na entrada. */

#define IN  1
#define OUT 0

int main()
{
    int c, newLine, newWord, newChar, state;

    state = OUT;
    newLine = newWord = newChar = 0;

    while ((c = getchar()) != EOF) {
        ++newChar;

        if (c == '\n')
            ++newLine;

        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;

        else if (state == OUT) {
            state = IN;
            ++newWord;
        }
    }

    printf("%d %d %d\n", newLine, newWord, newChar);
}
