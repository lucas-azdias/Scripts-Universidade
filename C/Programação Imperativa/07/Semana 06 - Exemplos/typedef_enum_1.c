#include <stdio.h>

enum Dia {SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO, DOMINGO};
typedef enum Dia Day;
// Para evitar de ter que declarar um ENUM com "enum <nome> <var>", pode-se usar o typedef

int main()
{
    Day D;
    printf("Digite um dia da semana [0 a 6]: ");
    scanf("%d", &D);
    switch(D)
    {
        case SEGUNDA: case TERCA: case QUARTA: case QUINTA: case SEXTA:
            puts("trabalho"); break;
        case SABADO:
            puts("compras"); break;
        case DOMINGO:
            puts("descanso"); break;
        default:
            puts("ERRO!");
    }
    return 0;
}
