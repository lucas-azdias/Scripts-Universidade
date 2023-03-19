// Exercício complementar 02

/*
2) Escreva um programa em C para calcular o fatorial de um número N digitado.
Use a estrutura for para gerar a sequência de termos.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

      system("chcp 65001"); // Configura o prompt para o UTF-8

      int n, sum = 1;

      printf("\nDigite o valor final: ");
      scanf("%d", &n);

      for (int i = 1; i <= n; i++) {
            sum *= i;
      }

      printf("\nResultado é %d", sum);

      return 0;
}
