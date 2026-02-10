- Vamos escrever um programa que conta o número de ocorrências de cada dígito, de caracteres de espaço em branco (blank, tab, newline) e todos os outros caracteres. Isso é artificial mas nos permite ilustrar diversos aspectos da linguagem C em um único programa.
- Existem 12 categorias de input, então por conveniência, usar um array para guardar o número de ocorrências de cada dígito é melhor do que 10 variáveis individuais.

```c
#include <stdio.h>

/* conta dígitos, espaços em branco, outros. */

int main()
{
    int c, i, nwhite, nother;
    int ndigit[10];
    
    nwhite = nother = 0;
    
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;
    
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else
            ++nother;
            
    printf("Digits: ");
    for (i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]);
    
    printf("White space: %d\nOther: %d", nwhite, nother);
    
    }
        
    
}
```
- A declaração `int ndigit[10];` diz que ndigits deve ser um array de 10 inteiros. Índices de arrays sempre começam em 0 em C, então os elementos são `ndigit[0], ndigit[1], ..., ndigit[9]`. Isso é refletido em *loops for* que inicializam e exibem o array.
- Um índice pode ser qualquer expressão inteira, o que inclui variáveis como **i** e constantes inteiras.

- Este programa em particular depende das propriedades da representação dos caracteres dos dígitos. Por exemplo, o teste `if (c >= '0' && c <= '9')` determina se o caractere em **c** é um dígito. Se for, o valor numérico deste digito é `c - 0`.
- Isso apenas funciona se `'0', '1', ..., '9'` tem valores crescentes consecutivos. Felizmente, isso é verdadeiro para todos os sets de caracteres.

- Por definição, **char** é apenas um inteiro pequeno, então variáveis **char** constantes são idênticas a **int**s em expressões aritméticas. Isso é natural e conveniente, por exemplo, `c-'0'` é uma expressão inteira com valor entre 0 e 9 correspondente ao caractere '0' ao '9' armazenados em C, e portanto, é um dígito valido para o array **ndigit**

- A decisão sobre o caractere ser um dígito, um espaço em branco ou qualquer coisa a mais, é feita na sequência:

```c
if (c >= '0' && c <= '9')
    ++ndigits[c-'0'];
else if (c == ' ' || c == '\t' || c == '\n')
    ++nwhite;
else
    ++nother;
```

- O padrão:

```c
if (condicao)
    declaracao
else if (condicao2)
    declaracao2
    ...
    ...
    ...
else
    declaracaon
```

- Ocorre diversas vezes em programas como uma forma de expressar uma decisão de múltiplos caminhos. As *condições* são avaliadas na ordem do topo para baixo até uma delas se satisfazer; a esse ponto, a *declaração* é executada e toda a construção das condições é encerrada. (Qualquer *declaração* podem ser múltiplas declarações fechadas por chaves { ... }). Se nenhuma das condições é satisfeita, a declaração após o bloco else é executada se estiver presente. Se o *else* final e sua *declaração* não existirem, como no contador de palavras, nenhuma ação é tomada. Podem existir indeterminados grupos de *else if (...)* entre o *if* inicial e o *else* final.
- Por uma questão de estilo e conveniência, é recomendado formatar a construção como foi mostrado. Se cada if fosse recuado além do else anterior, uma longa sequência de decisões sairia do lado direito da página.
- Também existem condições **switch**, discutiremos isso mais tarde. Elas fornecem outra maneira de expressar uma decisão de múltiplos caminhos. É particularmente adequada quando a condição é se alguma expressão inteira ou de caracteres corresponde a uma de um conjunto de constantes. 