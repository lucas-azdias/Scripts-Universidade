#include <stdio.h>

int main()
{
    for  (int i = 0, j = 10; ; ) // Segunda e terceira expressões como vazias (sem condição de parada gera um loop infinito)
    {
        printf("%d %d\n", i, j);
        i++;
        j--;
    }

    /*
    Expressões:
      int i = 0, j = 10; -> separado por "," por serem a mesma expressão
      " " -> VAZIO
      " " -> VAZIO
    */

  return 0;
}