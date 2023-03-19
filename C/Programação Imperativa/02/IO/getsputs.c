#include <stdio.h>

int main() {

      char nome[23];

      puts("Entre com um nome: ");
      gets(nome);
      puts("O nome é: ");
      puts(nome);
      puts("\n");
      return 0;

      // Puts -> mais simples do que Printf, porém mais complexo do que Putchar
      // Gets -> mais simples do que Scanf, porém mais complexo do que Getchar

}