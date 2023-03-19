#include <stdio.h>

typedef struct {
      char letra;
      int num;
      double dec;
} Data;

int main() {

      Data data;
      Data* p = &data;

      // A sintaxe para acesso de memória dos campos do struct é diferente
      //    pointer->campo;

      puts("");

      p->letra = 'l';
      printf("%c\n", p->letra);

      p->num = 69;
      printf("%d\n", p->num);
      
      p->dec = 0.69;
      printf("%lf\n", p->dec);

      return 0;
}
