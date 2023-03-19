#include <stdio.h>

int main()
{
    int x = 7;

    int y = ~x + 1;

    printf("%d\n", y);

    return 0;
}

/*
Se inverter o valor (usar o NOT), obtém-se (inverso - 1), então
precisa somar 1 para chegar no complemento de fato.
Ex.:
        0 1 1 ( 3)
(~)  1 0 0 (-4)
(+1) 1 0 1 (-3) -> DUAS OPERAÇÕES PARA COMPLEMENTO DO VALOR
*/
