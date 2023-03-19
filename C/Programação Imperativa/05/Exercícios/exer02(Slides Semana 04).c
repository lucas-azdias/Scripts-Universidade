#include <stdio.h>
#include <stdlib.h>

int main() {

      system("chcp 65001"); // Configura o prompt para o UTF-8

      const double PI = 3.141592635;
      int r = 0;

      double volume;

      do {
            volume = 4./3 * PI * pow(r, 3);
            printf("\nVolume de uma esfera com R=%d é %.2lf\n", r, volume);
            r += 2;
      } while (r <= 6);

      return 0;
}
