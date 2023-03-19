#include <stdio.h>
#include <string.h>

int main()
{
    char origem[30] = "Pantanal";
    printf("%s\n", origem);

    char destino[20];
    strcpy(destino, origem); // string copy -> copia apenas até o "\0"
    // destino = origem; -> Atribuição direta não funciona com Arrays (só poderia com atribuição de elemento por elemento)
    printf("%s\n", destino);

    return 0;
}
