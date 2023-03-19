#include <stdio.h>

typedef int INTEIRO;
typedef INTEIRO MeuInt;
// Cria sinônimos de sinônimos

int main()
{
    MeuInt x;

    printf("Digite um inteiro: ");
    scanf("%d", &x);
    printf("Valor digitado = %d\n", x);

    return 0;
}
