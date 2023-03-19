#include <stdio.h>
#include <stdlib.h>

void f(int** k)
{
    *k = (int*) malloc(sizeof(int));
    **k = 10;
}

/*
int** é o ponteiro de ponteiro de inteiro
*/

/*
Ocorre o uso de apenas uma cópia de um endereço
*/

int main()
{
    int* x = 0;
    f(&x);
    printf("%d\n", *x);

    return 0;
}
