#include <stdio.h>
#include <stdbool.h> // Biblioteca para usar BOOLEANS

// Adiciona o tipo BOOL, que pode assumir "true" ou "false"

int main()
{
    double temperatura;
    printf("Digite a temperatura [real entre -20 e 50]: ");
    scanf("%lf", &temperatura);

    double umidade;
    printf("Digite a umidade [real entre 0 e 1]: ");
    scanf("%lf", &umidade);

    bool frio;  // {true, false}
    bool calor; // {true, false}
    // frio e calor não podem ser true ao mesmo tempo,
    // mas podem ser false ao mesmo tempo, indicando "temperatura amena".

    if (temperatura < 10 || (temperatura < 20 && umidade > 0.8))
        frio = true;
    else
        frio = false;

    if (temperatura > 30 || (temperatura > 22 && umidade < 0.6))
        calor = true;
    else
        calor = false;

    if (frio)
        puts("Agasalhe-se bem!");
    else if (calor)
        puts("Beba bastante água!");
    else
        puts("Aproveite a temperatura amena para estudar bastante!");

    return 0;
}
