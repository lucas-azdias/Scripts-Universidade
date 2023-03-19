#include <stdio.h>

int main()
{
    for  (int i = 0, j = 10; i != j; i++, j--) // No FOR é possível envolver múltiplas variáveis no loop (porém é preciso respeitar o espaço de cada expressão)
    {
        printf("%d %d\n", i, j);
    }

    /*
    Expressões:
      int i = 0, j = 10; -> separado por "," por serem a mesma expressão
      i != j;
      i++, j-- -> separado por "," por serem a mesma expressão
    */

  return 0;
}