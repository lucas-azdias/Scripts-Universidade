#include <stdio.h>

int main()
{
    int k;
    scanf("%d", &k);
    switch ( k )
    {
        case 1: puts("UM"); break;
        case 2: puts("DOIS"); break;
        case 3: puts("TRÊS"); break;
        default: puts("DESCONHECIDO");
    }
    
    return 0;
}