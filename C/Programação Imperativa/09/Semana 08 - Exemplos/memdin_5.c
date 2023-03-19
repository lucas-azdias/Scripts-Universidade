#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Planeta {
    char nome[10];
    double raio;
    double distancia_do_sol;
    struct Planeta* proximo; // O bloco desse planeta aponta para o próximo (o último (cauda/tail) possui esse atributo como NULL e o primeiro (cabeça/head) é o com a posição salva)
    // É uma estrutura de lista baseada em nós que apontam para o seu próximo
    // É o equivalente ao que acontece com o List do Python
    // Existe a possibilidade de dupla ligação também (com um campo para o anterior e outro para o próximo)
};

int main()
{
    const size_t TAMANHO_ELEMENTO = sizeof(struct Planeta);

    struct Planeta* terra = (struct Planeta*) calloc(1, TAMANHO_ELEMENTO);
    strcpy(terra->nome, "Terra");
    terra->raio = 6378.0;
    terra->distancia_do_sol = 150000000.0;
    terra->proximo = NULL;

    struct Planeta* marte = (struct Planeta*) calloc(1, TAMANHO_ELEMENTO);
    strcpy(marte->nome, "Marte");
    marte->raio = 3396.0;
    marte->distancia_do_sol = 225000000.0;
    marte->proximo = terra;

    struct Planeta* jupiter = (struct Planeta*) calloc(1, TAMANHO_ELEMENTO);
    strcpy(jupiter->nome, "Jupiter");
    jupiter->raio = 71492.0;
    jupiter->distancia_do_sol = 750000000.0;
    jupiter->proximo = marte;

    struct Planeta* p = jupiter; // -> p é o head da lista
    while (p) // Quando p == NULL, ele para automaticamente
    {
        printf("%s\n", p->nome);
        p = p->proximo;
    }

    free(terra);
    free(marte);
    free(jupiter);

    return 0;
}
