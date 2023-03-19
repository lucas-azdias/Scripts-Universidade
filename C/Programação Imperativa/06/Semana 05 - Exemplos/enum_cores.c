#include <stdio.h>

// Pode-se usar o ENUM para declarar uma lista de constantes

enum Cores_do_semaforo { VERMELHO, VERDE, AMARELO };
// ENUM vai declarando os valores para as constantes de acordo com a posição
// e se for definido um valor específico para uma das variáveis, as constantes subsequentes seguirão essa nova enumeração
//      enum Cores_do_semaforo { VERMELHO = 4, VERDE, AMARELO }; -> {4, 5, 6}
//      enum Cores_do_semaforo { VERMELHO, VERDE = 7, AMARELO }; -> {0, 7, 8}

// const int VERMELHO = 0;
// const int VERDE = 1;
// const int AMARELO = 2;

int main()
{
    // No uso do ENUM, tem que declarar o nome dele
    enum Cores_do_semaforo s1 = VERDE; // cor do semáforo primário
    enum Cores_do_semaforo s2 = VERMELHO; // cor do semáforo secundário

    // int s1 = VERDE; // cor do semáforo primário
    // int s2 = VERMELHO; // cor do semáforo secundário

    printf("%d %d\n", s1, s2);

    if (s1 == VERDE)
        puts("permitido passar pelo semáforo primário");
    else if (s1 == VERMELHO)
        puts("obrigado a parar no semárofo primário");
    else
        puts("semáforo primário prester a fechar, atenção!");

    return 0;
}
