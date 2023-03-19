#include <stdio.h>

int main()
{
    // CONTINUE manda a execução de um loop para a próxima (FOR, WHILE ou DO-WHILE

    int i = 0; 
    do
    {
	    i++;
	    if  ( (i % 2) == 0 )
	        continue;
	    printf("i = %d\n", i);
    }
    while (i < 10);

    return 0;
}