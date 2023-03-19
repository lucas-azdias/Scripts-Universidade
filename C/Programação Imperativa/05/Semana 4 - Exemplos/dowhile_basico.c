#include <stdio.h>
	
int main()
{
    int i = 1;
    // DO-WHILE é igual ao WHILE, porém é invertido a verificação (é executado para depois se verificar)
    do
    {
        printf("i = %d\n", i);
        i++;
    }
    while(i < 10);
    
    return 0;
}
