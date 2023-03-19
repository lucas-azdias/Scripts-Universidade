#include <stdio.h>
#include <math.h>

#define SIZE 9

int main() {

      double vals[SIZE];

      printf("Digite os %d valores:\n", SIZE);
      for (int i = 0; i < SIZE; i++)
            scanf("%lf", &vals[i]);

      printf("\nMOSTRANDO RESULTADO...\n");
      for (int i = 0; i < ceil(SIZE / 2.); i++)
            printf("%lf ", vals[i] + vals[SIZE - i - 1]);
      puts("");

      return 0;
}
