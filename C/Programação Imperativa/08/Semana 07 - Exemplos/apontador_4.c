#include <stdio.h>

void imprimir(double* p, int COLS, int linha, int coluna)
{
    int offset = (linha*COLS) + coluna;
    p = p + offset;
    printf("matriz[%d][%d]=%f\n", linha, coluna, *p);
}

int main()
{
    double matriz[2][3];
    matriz[0][0] = 3.76;
    matriz[0][1] = 0.81;
    matriz[0][2] = 7.32;
    matriz[1][0] = 2.84;
    matriz[1][1] = 9.76;
    matriz[1][2] = 5.43;

    double* p = &matriz[0][0];
    
    imprimir(p, 3, 0, 2); // matriz[0][2]
    imprimir(p, 3, 1, 0); // matriz[1][0]

    return 0;
}
