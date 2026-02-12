/*
Exercise 1−16. Revise the main routine of the longest−line program so it will correctly print the length of
arbitrary long input lines, and as much as possible of the text.
*/

#include <stdio.h>
#define MAXLINE 20 /* tamanho máximo de uma linha da entrada. */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* Exibe a maior linha da entrada */
int main()
{
    int len; /* tamanho da linha atual */
    int max; /* tamanho máximo visto até então */
    char line[MAXLINE]; /* Atual linha da entrada */
    char longest[MAXLINE]; /* maior linha é salva aqui */
    
    max = 0;
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (line[len - 1] != '\n') {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                len++;
            if (c == '\n')
                len++;
        }

        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {/* tinha uma linha */
        printf("%s\n", longest);
        printf("%d\n", max);
    }
    return 0;
}

/* lê uma linha em s, retorna o comprimento */
int get_line(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < lim - 1 &&(c = getchar()) != EOF &&c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copia 'from' para 'into'; assumindo que 'to' é grande o suficiente. */
void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    
    while ((to[i] = from[i]) != '\0')
        ++i;
}