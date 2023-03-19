
#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool b[] = {true, false, false, true, true, false};
    int num_elementos = sizeof(b) / sizeof(bool);

    /*
    Para descobrir o tamanho de um Array de um tipo específico:
        "len = sizeof(Array) / sizeof(<type>)" -> (bytes do Array / bytes do tipo)
    */

    printf("Número de elementos: %d\n", num_elementos);
    for (int i = 0; i < num_elementos; i++)
    {
        if (b[i])
            puts("verdadeiro");
        else
            puts("falso");
    }
    return 0;
}
