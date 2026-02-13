/*
Exercise 1−17. Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>
#define MAXLINE 1000 /* tamanho máximo da linha */
#define LIMITE 80 /* se linha for maior que LIMITE... */

int get_line(char linha[], int maxline);

int main()
{
    int tan;
    char linha[MAXLINE];

    while ((tan = get_line(linha, MAXLINE)) > 0) {
        if (tan > LIMITE)
            printf("%s", linha);
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
