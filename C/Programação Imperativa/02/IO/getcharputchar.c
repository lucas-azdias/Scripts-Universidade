#include <stdio.h>

int main() {

  int c;

  puts("Entre um char: ");
  c = getchar();
  puts("Caracter digitado: ");
  putchar(c);
  putchar('\n');

  getchar(); // Consome o ENTER (que também é dado como um caracter)

  puts("Entre um char: ");
  c = getchar();
  puts("Caracter digitado: ");
  putchar(c);
  putchar('\n');

  return 0;

  // Putchar -> mais simples do que Puts e o Printf
  // Getchar -> mais simples do que Gets e o Scanf

}

// String: "a" -> |a\0| na memória (\0 é a indicação de fim da string)
// Char: 'a' -> |a| na memória

// Char pode ser armazenado em char ou int
// Int tem 4 bytes e char tem 1 byte