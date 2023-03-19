#include <stdio.h>
#include <string.h>

struct Pessoa
{
    char nome[50];
    int idade;
};

struct Pessoa g()
{
    struct Pessoa k;
    strcpy(k.nome, "Maria");
    k.idade = 20;
    return k;
}

int main()
{
    struct Pessoa x;
    x = g(); // É gerado mais uma cópia
    printf("%s\n", x.nome);
    printf("%d\n", x.idade);

    return 0;
}
