#include <stdio.h>

int x = 10; // declaração de variável global

void f()
{
    int x = 5; // declaração de variável local
    // local x = 5; global x inalterado
    x = x * 2; // acesso a variável local
    // local x = 10; global x inalterado
}

int main()
{
    x++; // acesso a variável global
    printf("%d\n", x);

    f();
    printf("%d\n", x);

    return 0;
}
