#include <stdio.h>
#include <string.h>

#define SIZE 50

int main() {

      char msg1[SIZE], msg2[SIZE], msgr[2 * SIZE];

      scanf("%s", msg1);
      scanf("%s", msg2);
      
      printf("\nMENSAGEM 1: %s\n", msg1);
      printf("\nMENSAGEM 2: %s\n", msg2);

      for (int i = 0; i < strlen(msg2); i++)
            if (strchr(msg1, msg2[i]) == NULL && strchr(msgr, msg2[i]) == NULL) {
                  strcpy(msgr, strcat(msgr, (char[2]) {msg2[i], '\0'}));
            }
      
      for (int i = 0; i < strlen(msg1); i++)
            if (strchr(msg2, msg1[i]) == NULL && strchr(msgr, msg1[i]) == NULL) {
                  strcpy(msgr, strcat(msgr, (char[2]) {msg1[i], '\0'}));
            }

      for (int i = 0; i < strlen(msgr); i++)
            for (int j = i + 1; i < strlen(msgr) - 1; i++)
                  if (msgr[i] > msgr[j]) {
                        char temp = msgr[i];
                        msgr[i] = msgr[j];
                        msgr[j] = temp;
                  }

      printf("\nREPETIDOS: %s\n", msgr);

      return 0;
}
