#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Pessoa
{
    char nome[50];
    int idade;
};

void f(struct Pessoa* k)
{
    strcpy(k->nome, "Maria");
    k->idade = 20;
}

int main()
{
    struct Pessoa* x = (struct Pessoa*) malloc(sizeof(struct Pessoa));
    f(x); // Não é gerado outra cópia
    printf("%s\n", x->nome);
    printf("%d\n", x->idade);

    return 0;
}
