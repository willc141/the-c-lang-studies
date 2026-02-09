- O quarto da nossa série de programas úteis conta linhas, palavras e caracteres, com a definição aproximada de que uma palavra é qualquer sequência de caracteres que não contenha um espaço em branco, tabulação ou nova linha. Esta é uma versão básica do programa UNIX wc.

```c
#include <stdio.h>

/* conta linhas, palavras e caracteres na entrada. */

#define IN  1
#define OUT 0

int main()
{
    int c, nl, nw, nc, state;
    
    state = OUT;
    nl = nw = nc = 0;
    
    while ((c = getchar()) != EOF) {
        ++nc;
        
        if (c == '\n')
            ++nl;
            
        if (c == ' ' || c == '\√' || c == '\n')
            state = OUT;
            
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    
    printf("%d %d %d\n", nl, nw, nc);
}
```

- Toda vez que o programa encontra o primeiro caractere de uma palavra, ele conta mais uma palavra. A variável **state** informa se o programa está em uma palavra ou não, inicialmente é 'não está em uma palavra', que está atribuído o valor de **OUT**. Optamos por usar constantes simbólicas para **IN** e **OUT** com os valores literais 1 e 0 já que fazem o programa ser mais legível.
- Em um programa pequeno como este, a diferença é mínima, mas em um programa grande, o aumento da clareza compensa bem o modesto esforço extra de escrever desta forma desde o início. Eventualmente, você descobrirá que é mais fácil fazer alterações extensas em programas onde "números mágicos" aparecem apenas como constantes simbólicas.

- A linha **nl = nw = nc = 0** atribui o valor 0 as três variáveis (nl, nw, nc). Este não é um caso especial, mas uma consequência do fato de uma atribuição ser uma expressão com o valor e as atribuições associadas da direita para a esquerda. É como se tivéssemos escrito **nl = (nw = (nc = 0))**;

- O operator || significa **OU**, então a linha:

```c
if (c == ' ' || c == '\n' || c == '\t')
```

- pergunta a máquina se **c** é um **espaço em branco** ou um **new line** ou um **tab** (O operador \t é uma representação visível do caractere **tab**). Tem um operador correspondente && para **E**; sua precedência é maior que ||. Expressões conectadas por && ou || são avaliadas da esquerda para a direita, e é garantido que a avaliação irá parar assim que o valor verdadeiro/falso for conhecido. Se **c** é um **espaço em branco**, não tem necessidade de checar se ele também é um **newline** ou um **tab**, então esses testes não são feitos. Isso não é realmente importante aqui, mas é significativamente mais importante em situações mais complexas.

- O exemplo também mostra um *else*, que especifica uma ação alternativa caso a condição *if* seja falsa. Numa forma geral, é assim:

```c
if (condicao) {
    expressao1
} else {
    expressao2
}
```