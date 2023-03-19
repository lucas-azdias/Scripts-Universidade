// Exercício complementar 03

/*
3) Fazer um programa em C para calcular o valor da série S abaixo.
O valor de N deve ser digitado. Use a estrutura do-while para somar a sequência de termos. 
      S = 1/N + 2/N-1 + 3/N-2 + ...+ N-1/2 + N/1 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

      system("chcp 65001"); // Configura o prompt para o UTF-8

      int n;
      double sum = 0;

      printf("\nDigite o valor final: ");
      scanf("%d", &n);

      for (int i = 1; i <= n; i++) {
            sum += i / (double) (n - (i - 1));
      }

      printf("\nResultado é %lf", sum);

      return 0;
}
