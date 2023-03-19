#include <stdio.h>

#define ROWS 3
#define COLS 3

double sum_diag_principal(double*, int, int);
double sum_diag_secundaria(double*, int, int);
void print_up_triangular_matrix(double*, int, int);

int main() {

      double matrix[ROWS][COLS] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

      printf("\nSoma da diagonal principal é %lf\n", sum_diag_principal(matrix, ROWS, COLS));
      printf("\nSoma da diagonal secundária é %lf\n", sum_diag_secundaria(matrix, ROWS, COLS));

      puts("\nMatriz triangular superior:");
      print_up_triangular_matrix(matrix, ROWS, COLS);

      return 0;
}

double sum_diag_principal(double* matrix, int rows, int cols) {
      // Retorna a soma da diagonal principal da matriz dada
      double sum = 0;
      for (int i = 0; i < rows; i ++) {
            sum += *(matrix + i * (1 + cols));
      }
      return sum;
}

double sum_diag_secundaria(double* matrix, int rows, int cols) {
      // Retorna a soma da diagonal secundária da matriz dada
      double sum = 0;
      for (int i = 0; i < rows; i ++) {
            sum += *(matrix + i * (cols - 1) + cols - 1);
      }
      return sum;
}

void print_up_triangular_matrix(double* matrix, int rows, int cols) {
      // Imprima a correspondente matriz triangular superior da matriz dada
      for (int i = 0; i < rows; i ++) {
            printf("| ");
            for (int j = 0; j < cols; j++){
                  double cur;
                  if (i <= j) {
                        cur = *(matrix + i * cols + j);
                  } else {
                        cur = 0;
                  }
                  printf("%lf ", cur);
            }
            printf("|\n");
      }
}
