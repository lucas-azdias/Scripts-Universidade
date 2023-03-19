#include <stdio.h>

// Array de múltiplas dimensões
// Para duas dimensões: matrix[num_rows][num_cols] (vetor de vetores)
// Na memória, é uma linha com todas as linhas em sequência
// O ponteiro para a matriz é declarado como:
//      <tipo>* pointer = &m[0][0];
//      <tipo>* pointer = m[0];
//      <tipo>* pointer = m;
// Para passar a posição de um ponteiro numa matriz da posição [i0][j0] para a [i][j], usa-se o cálculo:
//      p += (i - i0) * num_cols + (j - j0);
// Matriz é uma abstração em cima de uma forma linear

int main()
{
    int v[2][2] = {1, 2, 3, 4};
    printf("v[0][0]= %d\n", v[0][0]);
    printf("v[0][1]= %d\n", v[0][1]);
    printf("v[1][0]= %d\n", v[1][0]);
    printf("v[1][1]= %d\n", v[1][1]);

    int* p = &v[0][0];
    *p = 8;
    printf("v[0][0]= %d\n", v[0][0]);

    p++;
    *p = 7;
    printf("v[0][1]= %d\n", v[0][1]);

    p++;
    *p = 6;
    printf("v[1][0]= %d\n", v[1][0]);

    p++;
    *p = 5;
    printf("v[1][1]= %d\n", v[1][1]);

    return 0;
}
