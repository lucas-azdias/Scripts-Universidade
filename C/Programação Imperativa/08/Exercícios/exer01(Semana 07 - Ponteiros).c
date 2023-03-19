#include <stdio.h>

// Funções para manipulação de vetores
int ler_vetor(int*);
void imprime_vetor(int*);
int somatorio_vetor(int*);
void imprime_vetor_primos(int*);
int isprime(int n);

#define MAX 10

int main() {

      int vetor[MAX], erro=1;

      erro = ler_vetor(vetor); 
      if (erro != 0) {
            puts("Erro na leitura do vetor\n");
      } else {
            imprime_vetor(&vetor[0]);
            printf("\nO somatório dos elementos do vetor é %d\n", somatorio_vetor(vetor));
            imprime_vetor_primos(vetor);
      }

      return 0;
}

// Função para leitura do vetor de inteiros
int ler_vetor(int* vet) {
      puts(" Entre com os valores do vetor\n");
      for (int i = 0; i < MAX; i++) {
            printf("Vetor[%d]= ", i);
            scanf("%d", &vet[i]); 
      }

      return 0;
}

// Função para imprimir o vetor de inteiros
void imprime_vetor(int* vet) {
      printf(" Vetor= ");
      for (int i = 0; i < MAX; i++) {
            printf("%d, ", vet[i]);
      }
      printf("\n");
}

// Função para fazer o somatório dos elementos de um vetor de inteiros
int somatorio_vetor(int* vet) {
      int sum = 0;
      for (int i = 0; i < MAX; i++) {
            sum += vet[i];
      }

      return sum;
}

// Função para imprimir apenas os elementos primos de um vetor de inteiros
void imprime_vetor_primos(int* vet) {
      printf("\nOs valores primos do vetor são: ");
      for (int i = 0; i < MAX; i++) {
            if (isprime(vet[i]))
                  printf("%d, ", vet[i]);
      }
      printf("\n");
}

// Função que verifica se número é primo ou não
int isprime(int n) {
      if (n <= 1) {
            return 0;
      } else if (n % 2 == 0 && n > 2) {
            return 0;
      } else {
            for (int i = 3; i < n / 2; i += 2) {
                  if (n % i == 0) {
                        return 0;
                  }
            }
      }

      return 1;
}
