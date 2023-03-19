#include <stdio.h>

// define a estrutura Book e o seu sinônimo Livro:
typedef struct Book { char title[80]; int year; } Livro;
// Para evitar de ter que declarar um STRUCT com "struct <nome> <var>", pode-se usar o typedef

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
