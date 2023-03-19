#include <stdio.h>
#include <stdlib.h>

#define QTDE_NUM 10

int main() {

      puts("\nIniciando o programa...");


      // Cria blocos para armazenamento de números
      int* num_impares = (int*) calloc(QTDE_NUM, sizeof(int));
      int* num_pares = (int*) calloc(QTDE_NUM, sizeof(int));


      // Atribui os valores aos blocos alocados nos ponteiros
      for (int i = 0; i < QTDE_NUM; i++) {
            *(num_impares + i) = 2 * i + 1; // Recebe os ímpares entre 1 e 20
            *(num_pares + i) = 2 * (i + 1) + 20; // Recebe os pares entre 21 e 40
      }

      
      // Cria mais um bloco e armazena a junção dos anteriores
      int* num_concat = (int*) calloc(QTDE_NUM * 2, sizeof(int));
      for (int i = 0; i < QTDE_NUM; i++) {
            *(num_concat + i) = *(num_impares + i);
            *(num_concat + QTDE_NUM + i) = *(num_pares + i);
      }


      // Imprime todos os blocos
      puts("\nNúmeros ímpares entre 1 e 20:");
      for (int i = 0; i < QTDE_NUM - 1; i++) {
            printf("%d, ", *(num_impares + i));
      }
      printf("%d\n", *(num_impares + QTDE_NUM - 1));

      puts("\nNúmeros pares entre 21 e 40:");
      for (int i = 0; i < QTDE_NUM - 1; i++) {
            printf("%d, ", *(num_pares + i));
      }
      printf("%d\n", *(num_pares + QTDE_NUM - 1));

      puts("\nConcatenação dos dois blocos anteriores:");
      for (int i = 0; i < QTDE_NUM * 2 - 1; i++) {
            printf("%d, ", *(num_concat + i));
      }
      printf("%d\n", *(num_concat + QTDE_NUM * 2 - 1));


      puts("\nFim do programa.");


      return 0;
}
