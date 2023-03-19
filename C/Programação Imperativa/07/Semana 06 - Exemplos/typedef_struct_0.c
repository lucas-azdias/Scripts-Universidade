#include <stdio.h>

//define a estrutura Book:
struct Book { char title[80]; int year; };

int main()
{
    struct Book x;

    printf("Digite um título (sem espaços): ");
    scanf("%s", x.title);

    printf("Digite um ano: ");
    scanf("%d", &(x.year));

    printf("Livro: %s (%d).\n", x.title, x.year);

    return 0;
}
