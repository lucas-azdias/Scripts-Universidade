#include <stdio.h>

// Pode-se definir uma constante com:
//      1. "const <type> <name> = <value>" -> É definido uma variável de tipo específico com um valor específico
//      2. "#define <name> <value>" -> Compilador substitui name por value no código final (só avalia se o tipo coincide na etapa seguinte de compilação)
// No geral é recomendado usar o primeiro, mas pode haver situações específicas em que se deve usar o segundo

// const double PI = 3.14159;
// const int MAXIMO_POR_EQUIPE = 4;
// const char ARROBA = '@';

#define PI 3.14159
#define MAXIMO_POR_EQUIPE 4
#define ARROBA '@'

int main()
{
    printf("%f\n", PI);
    printf("%d\n", MAXIMO_POR_EQUIPE);
    printf("%c\n", ARROBA);
    return 0;
}

/*
#define size 10
int v[size]; -> funciona

const int size = 10;
int v[size] -> não funciona
*/
