#include <stdio.h>
#include <math.h>
    
void showbitsint( int x )
{
    int i=0;
    for (i = (sizeof(int) * 8) - 1; i >= 0; i--)
    {
       putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}

int main()
{
    for (int i = 0; i < 32; i++)
    {
        int n = pow(2, i);
        showbitsint(n);
    }

    return 0;
}
