#include <stdio.h>

int main()
{
  for  (int i = 0; i < 10; i++) // FOR possui 3 expressões: expr_inicial, expr_condição e expr_incremento (ou de decremento)
  {
      printf("%d\n", i);
  }
  
  /*
  Ordem de execução do FOR:
    1 - expr_inicial
    2 - expr_condição
    3 - CÓDIGO DO BLOCO
    4 - expr_incremento
    5 - expr_condição
    6 - CÓDIGO DO BLOCO
    7 - expr_incremento
    8 - expr_condição
    ...
  */

  return 0;
}