#include <stdio.h>

int main()
{
    int vogais = 0, consoantes = 0, hifens = 0;

    char palavra[80];
    printf("Digite um palavra: ");
    scanf("%s", palavra); // Não precisa por como endereço, pois a variável já é um pointer para a localização

    for (int i = 0; palavra[i] != '\0'; i++) // Passa por todos os caracteres até chegar ao fim da String (caractere '\0')
    // No CASE, se for igual ao atributo sendo verificado, inicia a execução do código
    // (e só termina ao fim, por isso precisa de um BREAK ao fim para não executar o restante dos códigos)
    switch ( palavra[i] )
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': vogais++; break; // (é executado para qualquer CASE acima se entrar na parte do código)
        case '-': hifens++; break;
        default:  consoantes++; // Não precisa de BREAK, pois o código já termina aqui
    }
    
    printf("vogais: %d, consoantes: %d, hifens: %d\n",
            vogais, consoantes, hifens);

    return 0;
}