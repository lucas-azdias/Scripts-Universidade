#include <stdio.h>

// "sizeof(var)" mostra tamanho em bytes da variável

enum Cores_do_semaforo { VERMELHO, VERDE, AMARELO };

int main()
{
    enum Cores_do_semaforo s1 = VERDE; // cor do semáforo primário

    printf("enum: %lu\n", sizeof(s1)); // 4

    return 0;
}