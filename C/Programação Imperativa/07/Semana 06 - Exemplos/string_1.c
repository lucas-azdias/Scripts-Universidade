#include <stdio.h>
#include <string.h>

int main()
{
    char* nome = "Vinicius de Moraes"; // -> Declaração de pointer
    // Será usado apenas o necessário para a atribuição (e a string continua sendo read-only, mas não o pointer)
    // "nome" será um pointer (o endereço para aonde há o endereço que referencia a string)

    printf("%s\n", nome);

    printf("espaço ocupado pela variável: %lu\n", sizeof(nome)); // Mostra quantidade de bytes ocupados pelo endereço da string (não da string)
    printf("comprimento da string: %lu\n", strlen(nome)); // Mostra quantidade de chars da string

    printf("%c\n", nome[0]);
    printf("%c\n", nome[1]);
    printf("%c\n", nome[17]);
    printf("%c\n", nome[18]);
    printf("%c\n", nome[30]);

    return 0;
}
