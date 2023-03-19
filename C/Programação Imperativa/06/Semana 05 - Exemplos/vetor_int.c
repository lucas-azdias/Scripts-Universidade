#include <stdio.h>

/*
Vetores (ou Arrays):
    Unidimensionais
    Multidimensionais (ou matrizes)
*/

// Vetores são estáticos (não pode mudar o tamanho)

// Definição: <type> <name>[<size1>][<size2>]...

/* Vetores multidimensionais são "Arrays de Arrays"
    Em "char nomes[2][] = {"nome1", {"nomesegundo"}}",
    -linhas = 2
    -colunas = (tamanho do maior nome) -> no caso, 13
*/

int main()
{
    // Pode-se omitir o tamanho do Array se ele for declarado em sequência (o compilador descobre depois)
    int numeros[] = {0, 1, 2, 3};
    // char nome[] = "abc" -> também funcionaria
    
    printf("int[]: %lu\n", sizeof(numeros));

    printf("%d\n", numeros[3]);

    return 0;
}
