// Exercício 02-01
// Dado um array de inteiros, encontre a maior subsequência crescente de elementos

#include <array>
#include <iostream>


int main() {
	// int size_array;
	// std::cout << "Tamanho array: "; // << -> Manda a string para o buffer de saída
	// std::cin >> size_array; // >> -> Recebe a string do buffer de entrada


	// Valores iniciais
	constexpr int size_array = 8;
	std::array<int, size_array> array = {10, 22, 9, 33, 21, 50, 41, 60};


	// Cálculo
	/*int max_index = 0;

	int beforeSum;
	int curSum;

	for (int i = 0; i < size_array; i++) {
		int numTry = array[i];
		int beforeTry = numTry;
		curSum = numTry;
		for (int j = 0; j < size_array - i; j++) {
			if (array[i + j] > beforeTry) {
				beforeTry = array[i + j];
				curSum += array[i + j];
			}
		}
		if (i == 0) {
			beforeSum = curSum;
		}
		if (curSum > beforeSum) {
			beforeSum = curSum;
			max_index = i;
		}
	}*/


	// Cálculo
	int max_index = 0;

	int beforeAmount = 0;
	int curAmount;

	for (int i = 0; i < size_array; i++) {
		int numTry = array[i];
		int beforeTry = numTry;
		curAmount = 0;

		for (int j = 0; j < size_array - i; j++) {
			if (array[i + j] > beforeTry) {
				beforeTry = array[i + j];
				curAmount++;
			}
		}

		if (curAmount > beforeAmount) {
			beforeAmount = curAmount;
			max_index = i;
		}
	}


	// Mostrando
	int beforeTry = 0;
	std::cout << "Max sequence is";
	for (int i = 0; i < size_array - max_index; i++) {
		if (array[max_index + i] > beforeTry) {
			beforeTry = array[max_index + i];
			std::cout << " " << array[max_index + i];
		}
	}
	std::cout << "\n";


	return 0;
}
