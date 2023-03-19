#include <stdio.h>
#include <string.h>

// Definindo novo STRUCT
// Variável composta com várias subvariáveis
struct Funcionario {
      char nome[50];
      float salario;
};

int main() {

      // Definindo uma instância da estrutura "Funcionario"
      struct Funcionario programador;

      strcpy(programador.nome, "Luís Paulo");
      programador.salario = 1230.89;

      // Ou "struct Funcionário programador = {"Luís Paulo", 1230.89};"

      printf("\nProgramador %s ganha %.2f\n", programador.nome, programador.salario);

      return 0;
}
