#include <stdio.h>
#include <string.h>

int main()
{
    char origem[30] = "Pantanal";
    printf("%s\n", origem);

    char destino[6];
    strcpy(destino, origem); // ERRO DE EXECUÇÃO -> tamanho insuficiente
    // Gera BufferOverflow do Array (por mais que funcione)
    printf("%s\n", destino);

    return 0;
}
