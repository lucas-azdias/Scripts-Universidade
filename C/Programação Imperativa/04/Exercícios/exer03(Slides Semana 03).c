#include <stdio.h>
#include <string.h>

int main() {
      
      int num;
      char qualquer[20];

      puts("Digite um valor inteiro:");
      scanf("%d", &num);

      puts("");

      if (num > 0) {
            //qualquer = "Positivo"; -> Não funciona
            strcpy(qualquer, "Positivo");
      } else if (num < 0) {
            //qualquer = "Negativo"; -> Não funciona
            strcpy(qualquer, "Negativo");
      } else {
            //qualquer = "Nulo"; -> Não funciona
            strcpy(qualquer, "Nulo");
      }

      puts(qualquer);

      return 0;
}
