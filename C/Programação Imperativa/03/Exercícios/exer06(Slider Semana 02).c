#include <stdio.h>

int main() {

      char c;

      printf("Type a number between 0 and 255:\n");
      scanf("%d", &c);
      
      printf("\nResult:\n");
      printf("In decimal: %d\n", c);
      printf("In hexadecimal: %x\n", c);
      printf("In char: %c\n", c);

      return 0;
}
