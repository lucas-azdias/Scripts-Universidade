#include <stdio.h>
#include <string.h>

int main()
{
    char* origem = "Pantanal";
    printf("%s\n", origem);

    char destino[20];
    strcpy(destino, origem); // string copy usando origem como um pointer
    printf("%s\n", destino);
    // Para o destino como pointer, precisa usar malock (alocação de memória)

    return 0;
}
