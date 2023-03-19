#include <stdio.h>
#include <string.h>

#define SIZE 50

int main() {

      char msg1[SIZE], msg2[SIZE], msgr[2 * SIZE];

      scanf("%s", msg1);
      scanf("%s", msg2);

      printf("\nMENSAGEM 1: %s\n", msg1);
      printf("\nMENSAGEM 2: %s\n", msg2);

      strcpy(msgr, strcat(msg1, msg2));
      printf("\nMENSAGEM RESULTANTE: %s\n", msgr);

      return 0;
}
