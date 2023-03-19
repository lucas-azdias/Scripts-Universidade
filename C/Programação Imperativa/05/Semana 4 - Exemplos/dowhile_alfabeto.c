#include <stdio.h>

int main()
{
    char letra;


    // código usando do-while:
    letra = 'a';
    do 
    {
        putchar(letra);
        letra++;
    }
    while (letra <= 'z');
    
    putchar('\n');


    // código usando while:
    letra = 'a';
    while (letra <= 'z')
    {
        putchar(letra);
        letra++;
    }
    
    putchar('\n');


    return 0;
}