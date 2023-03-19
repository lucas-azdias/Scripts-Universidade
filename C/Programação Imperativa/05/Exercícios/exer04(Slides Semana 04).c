// Exercício complementar 01

/*
1) Sendo H = 1 + 1/2 + 1/3 + 1/4 + ... 1/N, elaborar um programa. em C para gerar o número H.
O valor de N deverá ser lido. Use a estrutura for para somar a sequência de termos. 
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
            sum += 1./i;
      }

      printf("\nResultado é %lf", sum);

      return 0;
}
