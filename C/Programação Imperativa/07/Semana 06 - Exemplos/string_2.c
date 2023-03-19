#include <stdio.h>

int main()
{
    char pais[10] = "Brasil"; // String normal com 10 char (10 bytes)

    char estado[] = "Paraná"; // String com 7 char (7 bytes)

    char* cidade = "Curitiba"; // Pointer de string

    printf("%s, %s, %s\n", pais, estado, cidade);

    pais[2] = 'e';
    estado[1] = 'i';
    //cidade[5] = 'a'; // causa erro de execução

    printf("%s, %s, %s\n", pais, estado, cidade);

    return 0;
}
