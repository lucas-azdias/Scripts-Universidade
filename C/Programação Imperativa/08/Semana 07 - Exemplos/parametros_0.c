#include <stdio.h>

void f(int x) { x = 10; }

void g(int* x) { *x = 10; }

int main()
{
    int a = 5;
    
    f(a);
    printf("%d\n", a);

    g(&a);
    printf("%d\n", a);

    return 0;
}
