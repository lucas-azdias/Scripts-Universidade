#include <stdio.h>

int main() {
      
      double const PI = 3.1415926;
      double radius = 0, volume;

      while (radius <= 6) {
            volume = (4.0/3) * PI * pow(radius, 3);
            printf("\nradius = %.2lf\nvolume = %.2lf\n", radius, volume);
            radius += 2;
      }

      return 0;
}
