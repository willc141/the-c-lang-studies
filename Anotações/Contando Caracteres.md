- O próximo programa conta caracteres; ele é semelhante ao programa de cópia.

```c
#include <stdio.h>

/* Conta caracteres na entrada */

int main()
{
    long nc;
    
    nc = 0;
    
    while (getchar() != EOF)
        ++nc;
        
    printf("%ld\n", nc);
}

```

- A declaração `++nc;` introduz um novo operador, **`++`**, que significa **incremente 1**. Você também poderia escrever `nc = nc + 1`,  porém `++nc` é mais conciso e mais eficiente. Existe um operador correspondente, `--`, que significa **decremente 1**. Os operadores `++` e `--` podem ser operadores prefixos (`++nc` | `--nc`) ou operadores pós-fixos (`nc++` | `nc--`).
- Essas duas formas possuem valores diferentes em expressões, mas resumidamente por enquanto, tanto `++nc` e `nc++` incrementam em **nc**.

- O programa de contador de caracteres guarda seu contador em uma variável do tipo **long** no lugar de um **int**, inteiros **long** são pelo menos 32-bits. Ao mesmo tempo que em algumas máquinas, **int** e **long** possuem o mesmo tamanho, em outras de 16-bits, **int** armazena -32768 até +32767, e seria necessário relativamente pouco para sobrecarregar um contador **int**. A especificação de conversão `%ld` indica ao `printf` que o argumento correspondente é um inteiro longo.

- É possível lidar com números ainda maiores usando um **double** (um **float** de dupla precisão). Também usaremos um *loop for* no lugar de um *while* para ilustrar uma nova forma de escrever o programa.

```c
#include <stdio.h>

/* Conta caracteres na entrada; segunda versão */

int main() {

    double nc;
    
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}

```

- `printf` usa `%f` tanto para **float** quanto para **double**; `%.0f` suprime a saída do ponto flutuante e a parte fracionária, que é `0`.
- O corpo do loop for está vazio já que todo o trabalho é feito no teste e na parte de incremento. Porém as regras gramáticas de C dizem que um *loop for* precisa ter um corpo. O ponto e vírgula (;), chamado de *expressão nula*, está ali para satisfazer esse requisito. Deixamos-o em uma linha separada para deixar mais visível, mas também poderia ser feito assim:

```c
for (nc = 0; getchar() != EOF; ++nc);
```

- Antes de sairmos do programa de contador de caracteres, observe que se a entrada não possui nenhum caractere, o *while* ou o *for* falham na primeira chamada para **getchar**, e o programa produz 0, a resposta certa. Isso é importante. Uma das coisas legais sobre o *while* e o *for* é que eles testam no topo do loop, antes de prosseguir com o corpo. Se não há nada a fazer, nada é feito, mesmo que isso signifique nunca ir ao corpo do loop. Programas devem agir de forma inteligente quando recebem uma entrada com comprimento zero. As expressões *while* e o *for* ajudam a garantir que os programas realizam ações razoáveis com condições de retorno.