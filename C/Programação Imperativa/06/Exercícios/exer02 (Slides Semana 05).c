#include <stdio.h>

#define QTDE 2
#define SIZE 10

int main() {

      int vecs[QTDE][SIZE], vecr[SIZE];

      for (int i = 0; i < SIZE; i++)
            vecr[i] = 0;

      for (int i = 0; i < QTDE; i++) {
            printf("\nVetor %d:\n", i);
            for (int j = 0; j < SIZE; j++) {
                  scanf("%d", &vecs[i][j]);
                  vecr[j] += vecs[i][j];
            }
      }

      printf("\nMOSTRANDO RESULTADO...\n");
      for (int i = 0; i < QTDE + 1; i++) {
            if (i < QTDE) {
                  printf("\nVetor %d: ", i);
                  for (int j = 0; j < SIZE; j++)
                        printf("%d ", vecs[i][j]);
            }
            else {
                  printf("\nVetor resultado: ");
                  for (int j = 0; j < SIZE; j++)
                        printf("%d ", vecr[j]);
            }
      }
      puts("");

      return 0;
}
