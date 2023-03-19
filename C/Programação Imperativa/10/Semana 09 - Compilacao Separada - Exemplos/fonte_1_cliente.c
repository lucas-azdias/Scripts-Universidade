#include <stdio.h>

#include "fonte_1_servico.h"

int main()
{
    double x = 4.0;
    double y = dobrar(x);
    printf("y = %f\n", y);
    return 0;
}

/*
Forma mais simples para aglutinar os arquivos:
ao invés de por os protótipos direto no código, pôe-se em um arquivo cabeçalho (.h)
que depois é incorporado com o "#include".
*/
