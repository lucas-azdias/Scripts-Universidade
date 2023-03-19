#include <stdio.h>

int main()
{
    int k; // um valor entre 10 e 20, inclusive

    // Exemplo de requisição contínua até valor válido usando DO-WHILE
    do
    {
        printf("Digite um valor inteiro entre 10 e 20: ");
        scanf("%d", &k);
    }
    while (k < 10 || k > 20); // (k < 10 || k > 20) == (!(10 <= k <= 20))
    
    printf("Valor digitado: %d\n", k);
    
    return 0;
}