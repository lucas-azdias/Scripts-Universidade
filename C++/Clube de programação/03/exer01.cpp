#include <iostream>
#include <chrono>
#include <vector>


// Imprime um vetor
template <typename T>
void print_vector(const std::vector<T>& vector, std::string line_start, std::string line_end) {
	std::cout << line_start;
	for (const T& item : vector) {
		std::cout << item << " ";
	}
	std::cout << line_end;
}


// Imprime uma matriz
template <typename T>
void print_matrix(const std::vector<std::vector<T>>& matrix, std::string line_start, std::string line_end) {
	for (const std::vector<T>& vector : matrix) {
		print_vector(vector, line_start, line_end);
	}
}


// Multiplica as matrizes de inteiros
std::vector<std::vector<int>> multiply_matrices(
	const std::vector<std::vector<int>>& matrixA,
	const std::vector<std::vector<int>>& matrixB
) {
	// Variáveis iniciais
	int widthA = matrixA.size();
	int widthB = matrixB.size();
	int heightB = matrixB.front().size();

	// Cria as matrizes que serão usadas
	std::vector<std::vector<int>> result(widthA, std::vector<int>(heightB, 0));
	std::vector<std::vector<int>> matrixB_t;

	// Faz a transposta da Matrix B
	for (int i = 0; i < widthB; i++) {
		std::vector<int> line;
		for (int j = 0; j < heightB; j++) {
			line.push_back(matrixB.at(j).at(i));
		}
		matrixB_t.push_back(line);
	}

	// Efetua a multiplicação das matrizes
	for (int i = 0; i < widthA; i++) {
		const std::vector<int>* line_matrixA = &(matrixA.at(i));
		const std::vector<int>* line_matrixB_t = &(matrixB_t.at(i));
		for (int j = 0; j < heightB; j++) {
			int val = 0;
			for (int p = 0; p < widthB; p++) {
				val += (*line_matrixA).at(p) * (*line_matrixB_t).at(p);
			}
			result.at(i).at(j) = val;
		}
	}

	return result;
}


// MAIN
int main() {

	// Configuração inicial
	constexpr int MATRIX_SIDE = 1000;
	constexpr bool PRINT_RESULT_MATRIX = false;

	// Declaração das matrizes
	std::vector<std::vector<int>> matrixA;
	std::vector<std::vector<int>> matrixB;
	//std::vector<std::vector<int>> matrixA(MATRIX_SIDE, std::vector<int>(N, 1));
	//std::vector<std::vector<int>> matrixB(MATRIX_SIDE, std::vector<int>(N, 1));

	// Criando Matrix A
	for (int i = 0; i < MATRIX_SIDE; i++) {
		std::vector<int> line;
		for (int j = 0; j < MATRIX_SIDE; j++) {
			line.push_back(1);
		}
		matrixA.push_back(line);
	}

	// Criando Matrix B
	for (int i = 0; i < MATRIX_SIDE; i++) {
		std::vector<int> line;
		for (int j = 0; j < MATRIX_SIDE; j++) {
			line.push_back(1);
		}
		matrixB.push_back(line);
	}

	// Imprime o texto inicial
	std::cout << "MULTIPLICANDO MATRIZES..." << std::endl << std::endl;

	// Declaração da matriz resultante e os pontos de tempos
	std::vector<std::vector<int>> result;
	std::chrono::high_resolution_clock::time_point init, end;

	// Multiplica as matrizes e calcula o tempo transcorrido
	init = std::chrono::high_resolution_clock::now();
	result = multiply_matrices(matrixA, matrixB);
	end = std::chrono::high_resolution_clock::now();

	// Imprime o tempo transcorrido
	std::cout << "Tempo transcorrido:" << std::endl;
	std::cout << "| " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - init).count() << "ns" << std::endl;
	std::cout << "| " << std::chrono::duration_cast<std::chrono::milliseconds> (end - init).count() << "ms" << std::endl;

	// Imprime a matriz resultante se for requerido
	if (PRINT_RESULT_MATRIX) {
		std::cout << std::endl << "Matriz resultante:" << std::endl;
		print_matrix(result, "| ", "\n");
	}

	// Imprime o texto final
	std::cout << std::endl << "FIM DO PROGRAMA" << std::endl << std::endl;

	return 0;
}
