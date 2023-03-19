#include <stdio.h>

int main() {

      double num1, num2, result;

      printf("Type two float numbers:\n");
      scanf("%lf %lf", &num1, &num2);
      result = num1 / num2;
      printf("The result is: %.4f", result);

      return 0;
}
