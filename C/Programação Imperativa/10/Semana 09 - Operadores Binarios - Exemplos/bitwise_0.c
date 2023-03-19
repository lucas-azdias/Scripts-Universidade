#include <stdio.h>

/*
Bitwise operations -> operações com bits

Lógicos:
    AND (&),
    OR (|),
    XOR/OR exclusivo (^),
    NOT/Complemento de um (~).

Deslocamento de bits:
    Left shift/À esquerda (<<),
    Right shift/À direita (>>).


São operações que ocorrem bit a bit de uma variável:
Ex 1.:  0010 0101 1110 0100 (0x25E4)
        0110 1100 0101 0011 (0x6C53)
(&)   ->0010 0100 0100 0000 (0x2440)

Ex 2.:  0010 0101 1110 0100 (0x25E4)
        0110 1100 0101 0011 (0x6C53)
(|)   ->0110 1101 1111 0111 (0x6DF7)

Ex 3.:  0010 0101 1110 0100 (0x25E4)
        0110 1100 0101 0011 (0x6C53)
(^)   ->0100 1001 1011 0111 (0x49B7)

Ex 4.:  0010 0101 1110 0100 (0x25E4)
(~)   ->1101 1010 0001 1011 (0xDA1B)

Ex 5.:  0010 0101 1110 0100 (0x25E4)
(<< 4)->0101 1110 0100 0000 (0x5E40)
(equivale a multiplicar por uma potência de 2)

Ex 6.:  0010 0101 1110 0100 (0x25E4)
(>> 4)->0000 0010 0101 1110 (0x025E)
(equivale a dividir por uma potência de 2)
*/

void showbitschar(char ch)
{
    /*
    char -> 1 byte (8 bits)
    */
    for (int i = (sizeof(char) * 8) - 1; i >= 0; i--)
    {
        putchar(ch & (1u << i) ? '1' : '0');
        /*
        if (ch & (1u << i))
            putchar('1');
        else
            putchar('0');
        */

        /*
        Entendendo (ch & (1u << i)):
            1u -> 1 (unsigned) -> 000...0001
            (1u << i) -> faz um left shift no 1 para a quantidade em i (começa em 7 e termina em 0)
            (ch & (1u << i)) -> faz um AND com o resultado e se o bit de ch na posição i for 1, retorna 1, se não retorna 0.
                                (os outros bits ficam sempre zerados, pois para o 1u, apenas um bit é 1)
            No if, será dado 0, apenas se para aquele bit o AND resultar em 0 (assim, false), caso contrário, dará um número diferente de 0 (ou seja, true).
        */
    }
    printf("\n");
}

int main()
{
    for (char ch = 'A'; ch < 'z'; ch++)
    {
        printf("%c\t%d\t", ch, ch);
        showbitschar(ch);
    }

    return 0;
}
