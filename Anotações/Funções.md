- Uma *função* proporciona um meio conveniente de encapsular algum cálculo, que pode então ser usada sem se preocupar com sua implementação. Com funções propriamente implementadas, é possível ignorar como um trabalho é feito; saber o que ele faz é suficiente. C torna o uso de funções conveniente e eficiente; Você verá frequentemente uma função curta definida e chamada apenas uma vez, apenas porque ela esclarece alguma parte do código.
- Até então usamos apenas funções como *printf*, *getchar* e *putchar* que foram disponibilizadas para nós. Agora é a hora de escrever as nossas próprias funções. Já que C não possui um operador de exponenciação como o `**`, vamos ilustrar as mecânicas das funções escrevendo uma função power(m, n) para elevar um inteiro **m** para uma potência inteira positiva *n*. Isso é, o valor de power(2, 5) é 32. Está função não é uma rotina prática de exponenciação, uma vez que lida apenas com potências positivas de pequenos inteiros. (A biblioteca padrão possui uma função **pow(x, y)** que calcula x^y).

```c
#include <stdio.h>

int power(int m, int n);

int main()
{
    int i;
    
    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}

int power(int base, int n) {
    int i, p;
    
    p = 1;
    
    for (i = 1; i <= n; ++i)
        p = p * base;
        
    return p;
}
```

- A definição de uma função tem essa forma:
```
return-type function-name(parameter declarations, if any)
{
    declarations
    statements
}
```

- As definições de uma função podem aparecer em qualquer ordem e em um ou mais arquivos de origem, embora nenhuma função possa ser dividida entre arquivos.
- Se o programa de origem aparece em diversos arquivos, pode ser necessário dizer mais para compilar e carregar do que se tudo aparecesse em um único, porém essa é uma questão de sistema operacional, não um atributo da linguagem. No momento, vamos assumir que ambas as funções estão no mesmo arquivo, então qualquer coisa que você aprendeu sobre rodar programas C ainda irá funcionar.

- A função **power** é chamada duas vezes por **main**, na linha:

```c
printf("%d %d %d", i, power(2, i), power(-3, i));
```

- Cada chamada passa dois argumentos para **power**, que a cada vez, retorna um inteiro para ser formatado e exibido. Em uma expressão, powe(2, i) é um inteiro assim como **2** e **i** são. (Nem todas as funções produzem um inteiro, veremos isso mais tarde.

- A primeira linha de **power** em si:

```c
int power(int base, int n)
```

- Declara os tipos dos parâmetros e os seus nomes, e o tipo do resultado que a função retorna. Os nomes usados para os parâmetros de **power** são locais para **power**, ou seja, só existem lá e não podem ser chamados de fora; não são visíveis para outras funções; outras funções podem usar os mesmos nomes sem conflito. Isso também é verdadeiro para as variáveis **i** e **p**: o **i** em **power** não é relacionado ao **i** em **main**.
- Geralmente, usaremos o parâmetro para uma variável nomeada na lista entre parênteses em uma função. Os termos *argumento formal* e *argumento real* são, por vezes, usados para a mesma distinção.

- O valor que **power** calcula é retornado para o **main** com a declaração *return*. Qualquer expressão pode seguir *return*:

```c
return expression;
```

- Uma função não precisa retornar um valor; uma declaração return sem expressão causa controle, porém nenhum valor útil para ser retornado para quem está chamando a função, assim como “sair do final” de uma função ao atingir a chave direita. A função que está chamando pode ignorar o valor retornado por uma função.
- Também, existe uma declaração *return* no final da função **main**. Já que **main** é uma função como qualquer outra, ela deve retornar um valor para quem a chamar, que neste caso, é o ambiente que o programa está sendo executado. Tipicamente, um valor return de 0 implica que o programa encerrou normalmente; valores diferentes de 0 indicam que o programa encerrou de forma não esperada/fora do normal ou condição de terminação errônea. Com interesse de simplicidade, nós omitimos declarações *return* de nossa função main até esse ponto, porém iremos incluir elas daqui pra frente, como um lembrete de que programas devem retornar um valor de status pro seu ambiente.

- A declaração:

```c
int power(int base, int n)
```

- Antes do main, indica que power é uma função que espera receber dois parâmetros inteiros e retorna um inteiro. Essa declaração, que é chamado de *protótipo de função* precisa concordar com a definição e usos de **power**. É um erro se a definição de uma função ou qualquer uso dela não concorda com o seu protótipo.
- Nomes de parâmetros não precisam concordar, de fato, nomes de parâmetros são opcionais em um protótipo de função, então para o protótipo, poderiamos ter escrito:

```c
int power(int, int);
```

- Nomes bem escolhidos são bons para documentação de qualquer forma, então veremos eles e usaremos frequentemente.
- Uma nota histórica: a maior mudança entre o ANSI C e as versões anteriores é a forma como as funções são declaradas e definidas. Na definição original do C, a função power teria sido escrita assim:

```c
/* power: raise base to n-th power; n >= 0 */

power(base, n)

int base, n
{
    int i, p;
    
    p = 1;
    
    for (i = 1; i <= n; ++i)
        p = p * base;
        
    return p;
}
```

- Os parâmetros são nomeados dentro dos parenteses, e seus tipos são declarados antes de abrir as chaves; parâmetros não declarados são interpretados como um inteiro. (O corpo da função é o mesmo de antes).
- A declaração de **power** no topo do programa teria ficado assim:

```c
int power();
```

- Nenhuma lista de parâmetros foi permitida, então o compilador não pôde verificar se a função power estava sendo chamada corretamente. De fato, como por padrão se presumiria que power retornaria um int, toda a declaração poderia muito bem ter sido omitida.
- A nova sintaxe de protótipos de funções torna muito mais fácil para um compilador detectar erros no número de argumentos ou seu tipo. O estilo antigo de declaração e definição ainda funciona em ANSI C, pelo menos durante um período de transição, mas recomendamos enfaticamente que você use o novo formato quando tiver um compilador que o suporte.
