// Exercício complementar 04

/*
4) Elabore um programa em C para imprimir os 30 primeiros números naturais pares.
Use a estrutura for para gerar a sequência de termos.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

      system("chcp 65001"); // Configura o prompt para o UTF-8

      const int LEN = 30;

      puts("");
      for (int i = 0; i <= LEN; i += 2) {
            if (i == LEN) {
                  printf("%d\n", i);
                  break;
            }
            printf("%d, ", i);
      }
      
      return 0;
}
