/*
Exercise 1−17. Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>
#define MAXLINE 1000 /* tamanho máximo da linha */
#define LIMIT 80 /* se linha for maior que LIMIT... */

int get_line(char line[], int maxline);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > LIMIT)
            printf("%s", line);
    }
}

int get_line(char line[], int lim)
{
    int c, pos_atual;

    for (pos_atual = 0; pos_atual < lim - 1 &&(c = getchar()) != EOF &&c!='\n'; ++pos_atual)
        line[pos_atual] = c;
    if (c == '\n')
    {
        line[pos_atual] = c;
        ++pos_atual;
    }
    line[pos_atual] = '\0';
    return pos_atual;
}
