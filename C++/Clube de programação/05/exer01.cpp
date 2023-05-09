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

/*
int main() {

	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int sum = 0;
	for (const auto& num : v) {
		if (num % 2 == 0) {
			sum += num;
		}
	}

	std::cout << "Para o vetor:" << std::endl;
	print_vector(v, "", "\n\n");

	std::cout << "Soma dos pares: " << sum << std::endl;

	return 0;

}
*/