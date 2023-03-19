#include <stdio.h>

double dobrar(double);

int main()
{
    double x = 4.0;
    double y = dobrar(x);
    printf("y = %f\n", y);
    return 0;
}

/*
Para compilar dois ou mais arquivos juntos (combinando os protótipos das funções com os corpos de fato),
precisa compilar cada arquivo como um arquivo objeto (.o, que é um tipo semicompilado), para então compilar
todos os arquivos objetos juntos em um executável (.exe).

Essa semicompilação ajuda a não ter que recompilar todo o código em uma alteração, apenas em parte dele.
E para distribuir código de terceiro, sem ter acesso ao código-fonte.

Ex.:
gcc -c -o fonte_0_servico.o fonte_0_servico.c (faz o arquivo objeto de fonte_0_servico)
gcc -c -o fonte_0_cliente.o fonte_0_cliente.c (faz o arquivo objeto de fonte_0_cliente)

gcc -o fonte_0 fonte_0_servico.o fonte_0_cliente.o (faz o arquivo executável final)

-> -c -> força a não compilar em executável (apenas como arquivo objeto)
-> -o -> coloca um output file
*/
