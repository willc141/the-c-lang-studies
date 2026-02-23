A única forma de aprender uma linguagem de programação é escrevendo programas nela. O primeiro é sempre o mesmo:

```c
#include <stdio.h>

int main()
{
    printf("olá, mundo\n");
}
```

Para rodar no Unix: salve como `hello.c`, compile com `cc hello.c`, e execute com `./a.out`. Em outros sistemas, o processo pode variar.

---

## Estrutura básica de um programa C

Todo programa C é composto de **funções** e **variáveis**. Funções contêm as instruções a executar; variáveis guardam os valores usados durante a execução.

A função `main` é especial: todo programa começa a executar por ela. `main` pode chamar outras funções — algumas escritas por você, outras vindas de bibliotecas.

`#include <stdio.h>` na primeira linha diz ao compilador para incluir a biblioteca padrão de entrada e saída, que disponibiliza funções como `printf`.

---

## Chamando uma função

```c
printf("olá, mundo\n");
```

Uma função é chamada pelo nome seguido de parênteses com os argumentos. Aqui, `printf` recebe uma string e a exibe na tela. O `\n` ao final é o caractere de nova linha — sem ele, o cursor ficaria na mesma linha após a saída.

Strings entre aspas duplas como `"olá, mundo\n"` são chamadas de **constantes de string** ou **sequências de caracteres**.

---

## Resumo visual

| Elemento | O que faz |
|---|---|
| `#include <stdio.h>` | inclui a biblioteca padrão de I/O |
| `int main()` | define a função principal do programa |
| `{ }` | delimitam o corpo da função |
| `printf(...)` | exibe texto na saída |
| `\n` | caractere de nova linha |
