#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Pessoa
{
    char nome[50];
    int idade;
};

// Mais recomendado, pois ocorre a alocação na função
// e ocorre o retorno apenas do endereço

struct Pessoa* g() // É mais seguro, pois a própria função já aloca o espaço que usará
{
    struct Pessoa* k = (struct Pessoa*) malloc (sizeof(struct Pessoa));
    strcpy(k->nome, "Maria");
    k->idade = 20;
    return k;
}

int main()
{
    struct Pessoa* x;
    x = g();
    printf("%s\n", x->nome);
    printf("%d\n", x->idade);

    return 0;
}
