#include <stdio.h>

int main() {

      int num1, num2, q, r;

      printf("Type two integers:\n");
      scanf("%d %d", &num1, &num2);
      q = num1 / num2;
      r = num1 % num2;
      printf("Quotient: %d\nRest: %d", q, r);

      return 0;
}
