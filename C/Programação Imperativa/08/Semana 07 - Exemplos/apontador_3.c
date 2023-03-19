#include <stdio.h>

int main()
{
    double matriz[2][3]; // Posições totais = 6 -> (2 * 3) (ou seja, 48 bytes)
    matriz[0][0] = 3.76;
    matriz[0][1] = 0.81;
    matriz[0][2] = 7.32;
    matriz[1][0] = 2.84;
    matriz[1][1] = 9.76;
    matriz[1][2] = 5.43;

    double* p = &matriz[0][0];
    *p = 4.87;
    printf("matriz[0][0] = %f\n", matriz[0][0]);

    p = p + 4; // O avanço de posição se adapta ao tamanho do tipo de dado
    *p = 1.75;
    printf("matriz[1][1] = %f\n", matriz[1][1]);

    return 0;
}