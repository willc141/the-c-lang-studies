/*
Exercise 1−19. Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.
*/

#include <stdio.h>

#define LIMITE 1000

void reverse(char linha[]);
int get_line(char linha[], int maxline);

int main()
{
    int tam;
    char linha[LIMITE];

    while ((tam = get_line(linha, LIMITE)) > 0) {
        reverse(linha);
        printf("%s\n", linha);
    }
}

void reverse(char linha[])
{
    int i, j;
    char temp;

    j = 0;

    for (i = 0; linha[i] != '\0'; ++i);

    --i;

    if (linha[i] == '\n')
    {
        --i;
    }

    while (j < i) {
        temp = linha[j];
        linha[j] = linha[i];
        linha[i] = temp;
        --i;
        ++j;
    }
}

int get_line(char linha[], int lim)
{
    int c, pos_atual;

    for (pos_atual = 0; pos_atual < lim - 1 &&(c = getchar()) != EOF &&c!='\n'; ++pos_atual)
        linha[pos_atual] = c;
    if (c == '\n')
    {
        linha[pos_atual] = c;
        ++pos_atual;
    }

    linha[pos_atual] = '\0';

    return pos_atual;
}