#include <stdio.h>
#include <stdlib.h>

int main() {

      system("chcp 65001"); // Configura o prompt para o UTF-8

      const double PI = 3.141592635;

      double volume = 0;

      for (int r = 0; r <= 6; r += 2) { // Equivale a -> while (r <= 6) {r += 2}
            volume = 4.0/3 * PI * pow(r, 3);
            printf("\nVolume de esfera com R=%dm é %.2lfm³\n", r, volume);
      }

      return 0;
}