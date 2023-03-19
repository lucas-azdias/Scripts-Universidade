#include <stdio.h>

void dividir(int x, int y, int* q, int* r)
{
    *q = x / y;
    *r = x % y;
}

int calcular(int a, int b, int c, int d)
{
    int m, n, p, q;
    dividir(a, b, &m, &n);
    dividir(c, d, &p, &q);
    int resultado = m * p + n * q;
    return resultado;
}

int main()
{
    int r = calcular(54, 4, 14, 3);
    printf("%d\n", r);

    int x = 60, y = 7, p = 13, q = 2;
    printf("%d\n", calcular(x, y, p, q)); 

    return 0;
}
