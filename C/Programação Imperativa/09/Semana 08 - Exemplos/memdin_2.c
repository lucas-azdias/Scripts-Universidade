#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMERO_ELEMENTOS 10

int main()
{
    const size_t TAMANHO_ELEMENTO = sizeof(int);
    const size_t NUMERO_BYTES = NUMERO_ELEMENTOS * TAMANHO_ELEMENTO;

    int* buffer = (int*) calloc(NUMERO_ELEMENTOS, TAMANHO_ELEMENTO);

    printf("tamanho: %zu ==> %p\n", NUMERO_BYTES, buffer);

    buffer[4] = 500;
    printf("elemento na posição 4: %d\n", *(buffer+4));

    int* p = buffer + 4;
    *p = 800;
    printf("elemento na posição 4: %d\n", buffer[4]);

    free(buffer);

    return 0;
}
