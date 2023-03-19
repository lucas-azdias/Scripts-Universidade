#include <stdio.h>
#include <stdlib.h>

/*
A variável local de uma função é deletada após a execução dela, porém
a memória alocada por ela continua, assim sendo possível retornar o
endereço para ela sem problemas. 
*/

int* g()
{
    int* k = (int*) malloc(sizeof(int));
    *k = 10;
    return k;
}

/*
Ocorre o uso de duas cópias de um endereço
*/

int main()
{
    int* x;
    x = g();
    printf("%d\n", *x);

    return 0;
}
