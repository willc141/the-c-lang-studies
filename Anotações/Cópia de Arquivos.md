- Dado **getchar** e **putchar**, você pode escrever uma quantidade surpreendente de programas úteis sem saber muito mais que entrada e saída. O exemplo mais simples é um programa que copia a sua entrada para a sua saída um caractere por vez:

```exemplo
read a character
    while (character is not end-of-file indicator)
        output the character just read
        read a character
```

- Este programa, em C:

```c
#include <stdio.h>

int main()
{
    int c;
    
    c = getchar();
    
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
```

- O operador != significa "diferente de" ou também "não igual a".
- O que aparenta ser um caractere no teclado ou na tela, naturalmente, como todo o resto, é guardado internamente como um padrão de bits
- O tipo **char** é especificamente feito para armazenar esse tipo de dados de caracteres, porém qualquer tipo **int** pode ser usado. Usamos **int** por um motivo sutil, mas importante.

- O problema é distinguir o fim da entrada de dados válidos. A solução é que **getchar** retorna um valor distinto quando não existe mais entrada, um valor que não pode ser confundido com qualquer caractere real. Esse valor é chamado de EOF, para "end of file" (ou, fim do arquivo). Nós devemos declarar **c** para que ele seja um tipo grande o suficiente para armazenar qualquer valor que **getchar** retorne. Não podemos usar **char**, já que **c** precisa ser grande o suficiente para armazenar EOF em adição com qualquer possível **char**. Então, usamos **int**

- EOF é um **int** definido em <stdio.h>, porém o valor numérico específico não importa desde que ele não seja o mesmo que qualquer valor **char**. Usando uma constante simbólica, nós garantimos que nada no programa dependa do valor numérico específico.

- O programa para copiar seria escrito de forma mais concisa por programadores experientes. Em C, qualquer atribuição, como:

```c
c = getchar();
```

- é uma expressão e possui um valor, que é o valor do lado esquerdo após a atribuição. Isso significa que uma atribuição pode aparecer como a parte de uma expressão maior. Se a atribuição do caractere para a variável **c** é colocada dentro da parte de teste de condição do loop while, o programa pode ser escrito desta forma:

```c
#include <stdio.h>

int main()
{
    int c;
    
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}
```

- O while recebe um caractere, atribui-o para **c**, e então testa se o caractere era o sinal de fim-de-arquivo (EOF). Se não, o corpo do *loop while* é executado, exibindo o caractere. Então, o *loop while* se repete. Quando o fim da entrada é finalmente alcançado, o loop encerra e o programa continua fora do loop.
- Essa versão centraliza a entrada – Agora existe apenas uma referência para **getchar** – e diminui o tamanho do programa. O resultado é um programa mais compacto, e então, uma vez que a expressão é dominada, fica mais fácil de ler.
- Os parênteses em volta da atribuição, dentro da expressão, são necessários. A precedência de *!=* é maior que a de *=*, o que significa que, sem os parenteses, o teste *!=* seria feito antes da atribuição, então a expressão:

```c
c = getchar() != EOF
```

- É equivalente a:
`
```c
c = (getchar() != EOF)
```

- Isso tem o efeito indesejado de definir **c** como 0 ou 1, dependendo se a chamada **getchar** retornou ou não end-of-file (EOF)