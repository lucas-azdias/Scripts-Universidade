#include <stdio.h>
#include <math.h>
#include <limits.h>
    
void showbitsint( int x )
{
    int i=0;
    for (i = (sizeof(int) * 8) - 1; i >= 0; i--)
    {
       putchar(x & (1u << i) ? '1' : '0');
    }
}

void show(int x)
{
    printf("%20d: ", x); showbitsint(x);
    putchar('\n');
}

int main()
{
    show(0);
    show(1);
    show(2);
    show(-1);
    show(-2);

    puts("MAIOR INTEIRO:");
    show(INT_MAX);
    show(pow(2, 31) - 1); // Perde-se o 1 valor por causa do 0

    puts("MENOR INTEIRO:");
    show(INT_MIN);
    show(-pow(2, 31));

    return 0;
}

/*
Usa-se o complemento de dois (duas operações para o complemento)
para os inteiros:
    Para 3 bits (8 valores):
      sinal     valor
        0 1 1 ->  3
        0 1 0 ->  2
        0 0 1 ->  1
        0 0 0 ->  0
        1 1 1 -> -1
        1 1 0 -> -2
        1 0 1 -> -3
        1 0 0 -> -4
    
    Se inverter o valor (usar o NOT), obtém-se (inverso - 1), então
    precisa somar 1 para chegar no complemento de fato.
    Ex.:
         0 1 1 ( 3)
    (~)  1 0 0 (-4)
    (+1) 1 0 1 (-3) -> DUAS OPERAÇÕES PARA COMPLEMENTO DO VALOR
*/
