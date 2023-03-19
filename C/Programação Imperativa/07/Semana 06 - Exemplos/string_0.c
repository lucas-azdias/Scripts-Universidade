#include <stdio.h>
#include <string.h>

int main()
{
    char nome[20] = "Vinicius de Moraes";
    // Em atribuição literal na declaração, a string vira um read-only que funciona quase como uma constante (o compilador não possibilita modificação)
    // Se fosse separado, haveria possibilidade

    printf("%s\n", nome);

    printf("espaço ocupado pela variável: %lu\n", sizeof(nome)); // Mostra quantidade de bytes ocupados pela string
    printf("comprimento da string: %lu\n", strlen(nome)); // Mostra quantidade de chars da string

    printf("%c\n", nome[0]);
    printf("%c\n", nome[1]);
    printf("%c\n", nome[17]);
    printf("%c\n", nome[18]);
    printf("%c\n", nome[30]); // Compila! Mas, executa?

    return 0;
}
