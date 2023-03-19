#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

int main()
{
  char* buffer = (char*) malloc(1);
  printf("numero de bytes: %d ==> %p\n", 1, buffer);

  for (int i = 1; i <= MAX; i++) {
    const size_t NUMERO_BYTES = pow(2, i);

    buffer = (char*) realloc(buffer, NUMERO_BYTES);

    printf("numero de bytes: %zu ==> %p\n", NUMERO_BYTES, buffer);
  }

  free(buffer);
  
  return 0;
}
