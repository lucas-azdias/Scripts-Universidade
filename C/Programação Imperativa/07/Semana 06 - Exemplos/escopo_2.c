#include <stdio.h>

enum Cor {AZUL, VERMELHO, BRANCO}; // declaração de tipo global

void f()
{
    enum Marca {LG, Motorola, Apple}; // declaração de tipo local

    enum Cor cor_tel = VERMELHO; // declaração de variável de tipo global
    
    enum Marca marca_tel = Motorola; // declaração de variável de tipo local
}

int main()
{
    enum Cor cor_carro = AZUL;  // declaração de variável de tipo global
    enum Cor cor_casa = BRANCO; // declaração de variável de tipo global
    
    return 0;
}
