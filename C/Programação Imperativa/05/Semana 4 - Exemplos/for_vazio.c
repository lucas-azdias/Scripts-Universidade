#include <stdio.h>

int main()
{
    for  (int i = 0, j = 10; i != j; ) // Terceira expressão como vazia (expr_incremento ocorrendo no bloco)
    {
        printf("%d %d\n", i, j);
        i++;
        j--;
    }

    /*
    Expressões:
      int i = 0, j = 10; -> separado por "," por serem a mesma expressão
      i != j;
      " " -> VAZIO
    */

  return 0;
}