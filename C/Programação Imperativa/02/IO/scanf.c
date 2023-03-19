#include <stdio.h>

int main() {

      int n;
      float r; // De preferência use double

      int idade;
      float altura;

      char nome[10]; // Pode guardar até 9 caracteres (último é o /0)
      // Para um array (ou vetor), o endereço condiz com a primeira posição
      // (Em uma String, a última posição corresponde ao nulo (\0))
      //     Print de String['x', 'a', '\0', ..., '\0'] gera: "xa" (termina no primeiro caractere '\0')

      // & antes da variável passa o endereço de memória da variável
      // A máscara converte o valor para o seu respectível tipo (tratamento necessário)
      printf("Inteiro: ");
      scanf("%d", &n);
      printf("%d\n", n);

      printf("Real: ");
      scanf("%f", &r);
      printf("%f\n", r);

      printf("Digite a idade: ");
      scanf("%3d", &idade); // 3 -> Limite de caracteres lidos (resto é ignorado)
      printf("%d\n", idade);
      // Os caracteres ignorados ficam no Buffer de entrada e serão usados na próxima leitura
      // O Buffer usa a idéia de FIFO (First In, First Out)

      printf("Digite a altura: ");
      scanf("%5f", &altura); // O ponto conta como um caractere lido
      printf("%3.2f\n", altura);

      printf("Digite a idade e a altura:\n");
      scanf("%3d %5f", &idade, &altura); // Dá para digitar separando com Enter, Tab ou Space (esses caracteres servem de separador para o Scanf, ou seja, fim de dado)
      printf("%d\n", idade);
      printf("%3.2f\n", altura);

      printf("Digite o nome:\n");
      scanf("%s", nome); // Não é necessário passar com o &, pois um array/vetor já é um endereço naturalmente
      // Apenas lerá "Alan" se digitado "Alan Turing", pois o Scanf interpreta Space como fim da String (e insere '\0' nela)
      printf("nome = %s\n", nome[6]);

      fflush(stdin); // Limpa o Buffer (entrada ou saída)

      return 0;
}
