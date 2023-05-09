#include <iostream>
#include <algorithm>
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

	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::vector<int> v_result = v;
	/*for (const auto& num : v) {
		if (num % 3 == 0) {
			remove(v_result.begin(), v_result.end(), num);
			v_result.resize(v_result.size() - 1);
		}
	}*/
	v_result.erase(std::remove_if(v_result.begin(), v_result.end(), [](int num) { return num % 3 == 0; }), v_result.end());

	std::cout << "Para o vetor:" << std::endl;
	print_vector(v, "", "\n\n");

	std::cout << "Valores removendo os múltiplos de 3:" << std::endl;
	print_vector(v_result, "", "\n");

	return 0;

}
