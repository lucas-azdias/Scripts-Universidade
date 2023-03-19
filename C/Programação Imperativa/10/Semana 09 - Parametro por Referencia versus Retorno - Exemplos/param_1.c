#include <stdio.h>

void f(int* k)
{
    *k = 10;
}

int main()
{
    int x = 0;
    f(&x);
    printf("%d\n", x);

    return 0;
}

/*
Parâmetro é retornado por referência do endereço da variável

Através de uma atribuição no endereço da variável (ocupa o mínimo possível de memória)
*/
