- Existem diversas formas de escrever um único programa. Vamos tentar uma variação do conversor de temperatura:

```C
#include <stdio.h>

int main()
{
    
    for (int fahr = 0; fahr <= 300; fahr += 20) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr−32));
    }
}
```

- Este produz a mesma saída quando você executa o código, mas é definitivamente diferente. Uma das principais diferenças é a eliminação da maioria das variáveis que estavam presentes no código anterior; apenas o **fahr** permaneceu, e tornamos ele um int. As variáveis lower e upper, representando os limites, e o step size, aparecem apenas como *constantes no loop for*, em si uma nova construção, e a expressão que calcula a temperatura em Celsius agora aparece no terceiro argumento no printf, ao invés de uma atribuição separada.

- Esta última alteração é um exemplo de uma regra geral: em qualquer contexto em que seja permitido usar o valor de algum tipo, pode-se usar uma expressão mais complicada desse tipo. Já que o terceiro argumento do printf precisa ser um valor **float** para dar com o valor %6.1f, qualquer expressão **float** pode ocorrer aqui.

- A declaração **for** é um **loop**, uma generalização do **while**. Se você comparar com o **while** anterior, sua operação pode ser clara. Dentro dos parenteses, existem três partes, separadas por ponto e vírgula (;). 

- A primeira parte, é a inicialização, ela é feita uma vez, antes de entrar no loop propriamente dito:

```C
fahr = 0;
```

- A segunda parte, é o teste ou a condição que controla o loop. Se for verdadeira, o corpo do loop é executado.

```C
fahr <= 300 // fahr é menor ou igual a 300?
```

- Então, o passo de incremento é executado, e a condição é testada novamente. Caso a condição se torne falsa, o loop encerra e o programa continua fora do loop.

```C
fahr += 20
```

- Assim como o while, o corpo do loop pode ser uma única declaração ou um grupo de declarações entre chaves. A inicialização, condição e incrementação podem ser qualquer expressão 

- A escolha entre um **loop for** e um **loop while** são arbitrárias, baseado no que parece mais claro e funcional para o contexto. O **loop for** usualmente é apropriado para loops que a inicialização e incremento são declarações únicas e logicamente relacionadas, já que ele é mais compacto que o while e mantém o controle de declarações do loop juntos em um único lugar 