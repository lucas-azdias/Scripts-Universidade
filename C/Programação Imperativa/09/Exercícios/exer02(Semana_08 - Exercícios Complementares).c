#include <stdio.h>
#include <stdlib.h>

#define INITIAL_TEXT_SIZE 8
#define END_CHAR '1'

int main() {

      puts("\nIniciando o programa...");


      // Leitura de caracteres do usuário dinâmica
      char* text = (char*) malloc(INITIAL_TEXT_SIZE * sizeof(char));
      size_t textSize = INITIAL_TEXT_SIZE;
      size_t textLenght = 0;

      printf("\nDigite o texto abaixo (\"%c\" para parar):\n", END_CHAR);
      do {
            if (textLenght >= textSize) {
                  textSize += INITIAL_TEXT_SIZE;
                  text = (char*) realloc(text, textSize);
            }
            *(text + textLenght) = getchar();
            textLenght++;
      } while (*(text + textLenght - 1) != END_CHAR);
      textLenght--;
      *(text + textLenght) = '\0';

      fflush(stdin);


      // Imprime o texto
      printf("\nTexto digitado foi:\n\"%s\"\n", text);


      // Imprime dados do texto
      int count_a = 0;
      for (int i = 0; i < textLenght; i++) {
            if (*(text + i) == 'a') {
                  count_a++;
            }
      }
      printf("\nO texto possui %d caracteres, sendo %d de caracteres \"a\"\n", textLenght, count_a);


      // Imprime o texto invertido
      char* text_inv = malloc(textLenght * sizeof(char));
      for (int i = 0; i < textLenght; i++) {
            *(text_inv + i) = *(text + textLenght - i - 1);
      }
      *(text_inv + textLenght) = '\0';

      printf("\nTexto invertido ficaria:\n\"%s\"\n", text_inv);


      puts("\nFim do programa.");


      return 0;
}
