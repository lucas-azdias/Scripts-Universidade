#include <stdio.h>
#include <string.h>

int main() {

      char nome[] = "!UOTRECA";

      puts("");
      for (int i = strlen(nome) - 1; i >= 0; i--) {
            putchar(nome[i]);
      }
      puts("");
      
      return 0;
}
