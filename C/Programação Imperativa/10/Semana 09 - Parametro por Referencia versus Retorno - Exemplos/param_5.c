#include <stdio.h>
#include <string.h>

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
    struct Pessoa x;
    f(&x); // Não é gerado outra cópia
    printf("%s\n", x.nome);
    printf("%d\n", x.idade);

    return 0;
}
