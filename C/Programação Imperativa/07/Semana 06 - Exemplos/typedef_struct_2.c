#include <stdio.h>

// define uma estrutura inicialmente sem nome e a nomeia como Livro:
typedef struct { char title[80]; int year; } Livro;
// Declaração de typedef com o struct junto, mas sem nome para o struct

int main()
{
    Livro x;

    printf("Digite um título (sem espaços): ");
    scanf("%s", x.title);

    printf("Digite um ano: ");
    scanf("%d", &(x.year));

    printf("Livro: %s (%d).\n", x.title, x.year);

    return 0;
}
