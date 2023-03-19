#include <stdio.h>

int x = 10; // declaração de variável global

void f()
{
    x = x * 2; // acesso a variável global
}

int main()
{
    x++; // acesso a variável global
    printf("%d\n", x);

    f();
    printf("%d\n", x);

    return 0;
}
