#include <stdio.h>

int main()
{
    // BREAK quebra a execução de um loop (FOR, WHILE ou DO-WHILE)

    int i = 0; 
    do
    {
	    i++;
	    if  ( (i % 4) == 0 )
	        break;
	    printf("i = %d\n", i);
    }
    while (i < 10);

    return 0;
}