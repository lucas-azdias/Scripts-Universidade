#include <stdio.h>
#include <stdlib.h> // malloc(), calloc(), realloc(), free()
#include <math.h>

#define NUMERO_ELEMENTOS 10

// Memória usada pelo programa: código, dados iniciais e a parte livre para alocação póstuma

// malloc(int -> espaço a ser alocado) -> aloca o espaço desejado e retorna o endereço para ele (ponteiro de tipo void* que pode ser convertido ao tipo necessário) (retorna NULL se não for possível fazer a alocação)
//      > Ideal sempre verificar se houve sucesso na alocação (boa prática)
// calloc(int -> quantidade de blocos, int -> tamanho do bloco) -> aloca de blocos de memória contínuos e retorna o endereço para ele (ponteiro de tipo void* que pode ser convertido ao tipo necessário) (retorna NULL se não for possível fazer a alocação)
//      > Por convenção, o calloc (diferente do malloc) sempre zera toda a memória
// realloc(buffer -> endereço da memória já alocada, int -> nova quantidade de bytes) -> realoca a memória para o tamanho desejado aumentando ou diminuindo (pode continuar na mesma posição ou alterar para outra) e retorna o endereço para ele (ponteiro de tipo void* que pode ser convertido ao tipo necessário)
// free(buffer) -> desaloca a memória de buffer (para uma chamada única de malloc ou calloc)

int main()
{
    // size_t -> tipo padrão para guardar tamanho em bytes de um elemento (é equivalente a um unsigned int, mas não há garantia, pois pode atingir valores maiores)
    const size_t TAMANHO_ELEMENTO = sizeof(char);
    const size_t NUMERO_BYTES = NUMERO_ELEMENTOS * TAMANHO_ELEMENTO;

    char* buffer = (char*) malloc(NUMERO_BYTES);
    // Precisa converter o tipo de ponteiro com cast para o desejado (vem como void*)

    printf("tamanho: %zu ==> %p\n", NUMERO_BYTES, buffer);

    buffer[4] = 'w';
    printf("elemento na posição 4: %c\n", *(buffer+4 /*salta 4B*/));

    char* p = buffer + 4;
    *p = 'z';
    printf("elemento na posição 4: %c\n", buffer[4]);

    free(buffer);
    // O ideal é sempre desalocar ao término do uso da memória (por mais que um bom OS geralmente já desaloque ao término do programa, porém não há garantia)
    // Caso tente acessar a memória depois de ser desalocada, ocorre "dangling reference"

    return 0;
}
