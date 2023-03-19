#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char nome[10]; // 10B
    double raio; // 8B
    double distancia_do_sol; // 8B
    // Variáveis ocupam 26B ao todo
} Planeta; // Mas o Struct todo ocupa 32B ao todo 
           // (ocorre por 32B ser o múltiplo de 8 mais próximo de 26 e maior que ele,
           // já que o computador precisa alocar memória em múltiplos de 8B para maior
           // velocidade (o acesso da CPU poderia ocorrer duas vezes apenas para um
           // espaço, pois as CPUs são 64b (8B) assim sempre acessam 8B a cada vez))

#define NUMERO_ELEMENTOS 10

int main()
{
    const size_t TAMANHO_ELEMENTO = sizeof(Planeta);
    const size_t NUMERO_BYTES = NUMERO_ELEMENTOS * TAMANHO_ELEMENTO;

    Planeta* buffer = (Planeta*) calloc(NUMERO_ELEMENTOS, TAMANHO_ELEMENTO);

    printf("tamanho: %zu ==> %p\n", NUMERO_BYTES, buffer);

    // Acesso de parâmetro de um Struct, se for direto pelo conteúdo é por ".", se for por ponteiro é por "->"

    strcpy(buffer[4].nome, "Terra");
    buffer[4].raio = 6378.0;
    buffer[4].distancia_do_sol = 150000000.0;
    printf("elemento na posição 4: %s\n", (buffer+4)->nome);

    Planeta* p = buffer + 4;
    strcpy(p->nome, "Marte");
    printf("elemento na posição 4: %s\n", buffer[4].nome);

    free(buffer);

    return 0;
}
