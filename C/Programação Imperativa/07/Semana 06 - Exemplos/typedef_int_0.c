#include <stdio.h>

typedef int INTEIRO;
// typedef <tipo existente> <tipo novo>
// Cria sinônimos de tipos já existentes (tipos equivalentes ao original)
// É mais útil quando usado com ENUM ou STRUCT

int main()
{
    INTEIRO x;

    printf("Digite um inteiro: ");
    scanf("%d", &x);
    printf("Valor digitado = %d\n", x);

    return 0;
}