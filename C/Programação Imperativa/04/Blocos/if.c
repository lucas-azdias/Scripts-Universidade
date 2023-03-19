#include <stdio.h>

int main() {

      /*As chaves montam um bloco de comando*/

      /*
      Expressões lógicas (retornam inteiro e usam operadores relacionais e lógicos)
            Operadores relacionais são ==, <, <=, >, >= e !=
            Operadores lógicos são && (and), || (or) ou ! (not)
      */
     
     /*Chaves são opcionais se haver apenas uma linha de comando*/
      if (1 == 5 && 9 == 0) { /*Na expressão lógica, pode-se usar qualquer expressão de retorno inteiro, mas o ideal são as lógicas*/
            puts("Verdadeiro"); 
            /*Executa se o retorno for diferente de 0*/
      } else {
            puts("Falso");
            /*Executa se o retorno for igual a 0*/
      }

      /*
      Sempre haverá uma estrutura padrão e correspondente de if-else (mesmo com else if)
      */

      if (9 == 9)
            puts("Verdadeiro");

      return 0;
}
