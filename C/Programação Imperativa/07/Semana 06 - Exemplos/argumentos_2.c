#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("ERRO: número incorreto de argumentos!\n");
        printf("Uso: copiar <arquivo-entrada> <arquivo-saída>\n");
        return 10;
    }

    char* arquivo_entrada = argv[1];
    char* arquivo_saida = argv[2];

    printf("Copiando conteúdo de %s para %s ...\n",
            arquivo_entrada, arquivo_saida);
    
    return 0;
}
