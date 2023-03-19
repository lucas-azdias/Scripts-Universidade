#include <stdio.h>

int main() {

      // printf(mascara[String], valorASerImprimido)

      printf("%10.14s", "jararaca deita e rola"); printf("\n");
      // Máscara para Strings:
      // %00 -> espaços reservados na memória (mínimo a ser imprimido)
      // %-00 -> se sobrar espaço, ele põe as sobras no outro lado
      // %.00 -> limite de caractéres para ser imprimidos da String inicial

      printf("%d", 65); printf("\n");
      // Máscara para Int em Base10

      printf("%c", 'a'); printf("\n");
      // Máscara para Caracteres

      printf("%f", 333.999); printf("\n");
      // Máscara para Float ou Double

      printf("%d%.14s", 34, "IIIRRRRRAAAAAAAAa"); printf("\n");
      // Combinação de máscaras:
      // 1a parte da máscara -> 1o valor
      // 2a parte da máscara -> 2o valor
      // na parte da máscara -> no valor

      printf("%.2f", 333.999); printf("\n");
      // Máscara para Float ou Double

      return 0;

      // Só aceita String (para outros tipos, precisa explicitar)
      
      // Printf -> mais complexo do que Puts e Putchar
      // Scanf -> mais complexo do que Gets e Getchar

}