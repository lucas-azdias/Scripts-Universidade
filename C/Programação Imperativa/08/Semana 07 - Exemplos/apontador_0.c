#include <stdio.h>
#include <string.h>

/*
    Para referenciar um vetor: (pelo vetor ser um pointer do primeiro valor do vetor)
        pnt_vetor = vetor
        ou
        pnt_vetor = &vetor[0] -> quando usa os parênteses, acessa a memória do vetor

    Se incrementar/decrementar o pointer do vetor ou o vetor, gera a passagem pelos valores contidos no vetor (avança para o próximo endereço)
    O ponteiro então avança a quantidade de bytes do seu tipo (por isso sua importância)
*/

int main()
{
    char palavra[10] = "Jiboia";
    int comprimento = strlen(palavra); // 6
    for (int i = 0; i < comprimento; i++)
        printf("%c\n", palavra[i]);
    puts("=======");

    char* p = palavra;
    printf("%c\n", *p); // J
    p++;
    printf("%c\n", *p); // i
    p++;
    printf("%c\n", *p); // b
    p++;
    printf("%c\n", *p); // o
    p++;
    printf("%c\n", *p); // i
    p++;
    printf("%c\n", *p); // a
    puts("=======");

    p = palavra;
    for (int i = 0; i < comprimento; i++)
        printf("%c\n", *(p+i));
    puts("=======");

    return 0;
}