#include <iostream>
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


int main() {
	
	constexpr int SIZE = 7;
	std::vector<int> vendas{ 3, 4, 7, 1, 2, 6, 9 };

	// Obtém a maior variação
	int min_i = 0;
	int max_i = 0;
	for (int i = 1; i < SIZE; i++) {
		if (vendas[i] < vendas[min_i]) {
			min_i = i;
		}
		else if (vendas[i] > vendas[max_i]) {
			max_i = i;
		}
	}

	//// Obtém a subsequência contígua de maior variação
	//std::vector<int> seq_cont;
	//int max_var = 0;
	//int max_index = 0;
	//for (int i = 0; i < SIZE; i++) {
	//	int var = 0;
	//	for (int j = 0; j < SIZE - i; j++) {
	//		var += vendas[j + i] - vendas[i];
	//	}
	//	std::cout << var / (SIZE - i) << " ";
	//	if (var > max_var) {
	//		max_var = var;
	//		max_index = i;
	//	}
	//}

	// Imprime os resultados
	std::cout << "Vetor sendo analisado:" << std::endl;
	print_vector(vendas, "", "\n\n");
	std::cout << "A maior variação será entre os valores " << vendas[min_i] << " e " << vendas[max_i] << std::endl << std::endl;
	//std::cout << "Maior subsequência contígua de maior variação:" << std::endl;
	//print_vector(seq_cont, "", "\n\n");
	//std::cout << max_var << " " << max_index;

	return 0;
}
