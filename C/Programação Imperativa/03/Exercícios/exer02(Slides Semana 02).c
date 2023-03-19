#include <stdio.h>

int main() {

      double num1, num2, sum;

      printf("Type two float numbers:\n");
      scanf("%lf %lf", &num1, &num2);
      sum = num1 + num2;
      printf("The sum is: %.2f", sum);

      return 0;
}
