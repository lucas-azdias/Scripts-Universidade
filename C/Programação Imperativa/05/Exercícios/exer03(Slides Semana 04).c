#include <stdio.h>
#include <stdlib.h>

int main() {

      system("chcp 65001"); // Configura o prompt para o UTF-8

      double val1, val2, result;
      char op;

      puts("");

      printf("Digite dois valores: ");
      scanf("%lf %lf", &val1, &val2);

      fflush(stdin);

      printf("Digite a operação: ");
      scanf("%c", &op);
      
      switch (op) {
            case '+': result = val1 + val2; break;
            case '-': result = val1 - val2; break;
            case '*': result = val1 * val2; break;
            case '/': result = val1 / val2; break;
      }

      printf("Resultado é %.2lf\n", result);

      return 0;
}

