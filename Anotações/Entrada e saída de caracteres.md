
- Vamos considerar uma "familia" de programas relacionados para processamento de dados de caracteres. Você perceberá que muitos programas são apenas versões expandidas dos protótipos que vimos até então.
- O modelo de entrada e saída suportado pela biblioteca padrão é bem simples. Entrada ou saída de texto, independentemente da sua origem ou destino, é tratado como fluxo de caracteres. Um *fluxo de texto* é uma sequência de caracteres divididos por linhas; cada linha consiste por zero ou mais caracteres seguidos de um caractere de nova linha (\n). É responsabilidade da biblioteca fazer cada cada fluxo de entrada ou saída confirmar esse modelo. O programador C usando a biblioteca não precisa se preocupar sobre como linha são representadas fora do programa.

- A biblioteca padrão de entrada e saída disponibiliza diversas funções para ler ou escrever um caractere por vez. *getchar* e *putchar* são os mais simples. Toda vez que é chamado, **getchar** lê o próximo *caractere de entrada* de um fluxo de texto e retorna isso ao seu valor. Ou seja, depois de:

```c
c = getchar();
```

- A variável *c* possui o próximo caractere de entrada. O caractere normalmente vem pelo teclado.
- A função **putchar** exibe um caractere toda vez que é chamado:

```c
putchar(c);
```

- Exibe o conteúdo da variável de tipo **int** chamada **c** como um caractere. As chamadas para **putchar** e **printf** podem ser intercaladas. A saída irá aparecer na ordem que as chamadas são feitas.