- O próximo programa conta quantas linhas a entrada possui. Como mencionado anteriormente, a biblioteca padrão de entrada e saída certifica que um fluxo de texto de entrada apareça como uma sequência de linhas, cada uma terminada com um caractere de nova linha (\n). Então, contar linhas é apenas contar novas linhas (\n):

```c
#include <stdio.h>

/* contar linhas da entrada */

int main()
{
    int c, n1;
    
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++n1;
            
    printf("%d\n", n1);
}
```

- O corpo do *loop while* agora consiste em um *if* que controla o incremento **++n1**. A expressão *if* testa a condição que está dentro dos parenteses, e caso a condição seja verdadeira, executa as linhas de código dentro do if. Novamente, usamos a indentação para afirmar qual parte do código está sendo controlada pelo while/pelo if.
- O sinal == é a notação C para **é igual a**. Este símbolo é usado para distinguir o teste de igualdade do único =, que neste caso, na linguagem C é usado para atribuição.
- Um caractere escrito entre aspas simples ('a') representa um valor inteiro igual ao valor numérico do caractere no set de valores de caracteres da máquina. Isso é chamado de constante de caractere, mesmo que seja só uma forma de escrever um inteiro pequeno. Então, por exemplo, 'A' é um caractere constante; na tabela ASCII seu valor é 65, a representação interna do caractere **A**. É claro que **A** é preferível a 65: o seu significado é óbvio e é independente de um conjunto de caracteres específico.

- As sequências de escape usadas em constantes de strings também são válidas em constantes de caracteres, então, '\n' fica para o valor de newline (nova linha) na tabela ASCII, que, no caso, é 10. Você deve ter cuidado e notar que '\n' é um único caractere, e em expressões, ele é apenas um inteiro, em outra mão, '\n' é uma constante de string que possui apenas um caractere.