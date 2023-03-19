#include <stdio.h>

int main(int argc, char* argv[])
// chamado programa no terminal -> "$./programa a b c"
// argc -> contador de argumentos ("argc = 4" nesse caso)
// argv -> argumentos
//      #1 argumento -> "programa" (sempre será o nome do programa)
//      #2 argumento -> "a"
//      #3 argumento -> "b"
//      #4 argumento -> "c"
{
    printf("Número de argumentos: %d\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("Argumento %d: %s\n", i, argv[i]);
    }
    
    return 0;
}
