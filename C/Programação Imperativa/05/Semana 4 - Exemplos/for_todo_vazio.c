#include <stdio.h>

int main()
{
    int i = 0, j = 10;

    for  ( ; ; ) // Todas as expressões como vazias (sem condição de parada gera um loop infinito)
    {
        printf("%d %d\n", i, j);
        i++;
        j--;
    }

    /*
    Expressões:
      " " -> VAZIO
      " " -> VAZIO
      " " -> VAZIO
    */

  return 0;
}