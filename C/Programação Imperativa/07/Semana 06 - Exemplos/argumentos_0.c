#include <stdio.h>

int main(int argc, char* argv[])
// chamado programa no terminal -> "$./programa"
// argc -> contador de argumentos ("argc = 1" nesse caso)
// argv -> argumentos
//      #1 argumento -> "programa" (sempre será o nome do programa)
{
    printf("Número de argumentos: %d\n", argc);
    printf("Primeiro argumento: %s\n", argv[0]);

    return 0;
}
