#include <stdio.h>

int g()
{
    return 10;
}

int main()
{
    int x = 0;
    x = g();
    printf("%d\n", x);

    return 0;
}

/*
Parâmetro é retornado diretemente

Através de uma cópia do valor (ocupa o dobro de memória)
*/
