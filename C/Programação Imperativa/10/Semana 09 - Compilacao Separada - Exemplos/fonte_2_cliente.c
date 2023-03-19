#include <stdio.h>

#include "fonte_2_servico.h"

int main()
{
    double x = 4.0;
    double y = dobrar(x);
    printf("y = %f\n", y);
    return 0;
}

/*
Em um projeto, pode ser que um cabeçalho seja compilado mais de duas vezes, o que resultaria em erro,
assim, há as diretivas do cabeçalho para impedir a bicompilação.

No topo do cabeçalho se põe:
"
#ifndef SERVICO_H (só será compilado se ele já não tiver sido)
#define SERVICO_H (caso não tenha sido definido, então defina)

-> CORPO DO CABEÇALHO

#endif (termina o se)
"
*/
