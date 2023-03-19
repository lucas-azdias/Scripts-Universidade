#include <stdio.h>

int main()
{
    char* cantor = "John Lennon";
    cantor = "Nina Simone"; // Pointer começa a apontar para outro endereço de string

    const char* planeta = "Terra"; // CONST se refere apenas ao conteúdo ao qual o pointer se refere
    planeta = "Venus";

    char* const estrela = "Sol"; // CONST se refere ao pointer
    // estrela = "Maia"; // ERRO DE COMPILAÇÃO

    const char* const constelacao = "Gemini"; // CONST para o conteúdo e para o pointer
    // constelacao = "Taurus"; // ERRO DE COMPILAÇÃO
    // Garante que outro pointer não consiga modificar o conteúdo ao qual este pointer se referencia

    return 0;
}
