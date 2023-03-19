#include <stdio.h>
#include <stdbool.h>

// "sizeof(var)" mostra tamanho em bytes da variável

int main()
{
    bool calor = false;

    printf("bool: %lu\n", sizeof(calor)); // 1

    return 0;
}
