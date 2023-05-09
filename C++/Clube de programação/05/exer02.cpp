#include <iostream>
#include <algorithm>
#include <set>
#include <string>


// Imprime um set
template <typename T>
void print_set(const std::set<T>& set, std::string line_start, std::string line_end) {
	std::cout << line_start;
	for (const T& item : set) {
		std::cout << item << " ";
	}
	std::cout << line_end;
}


bool is_vogal(char letra) {
	std::set<char> vogais = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	// auto encontrado = std::find(vogais.begin(), vogais.end(), letra);
	if (vogais.find(letra) != vogais.end()) {
		return true;
	}
	else {
		return false;
	}
}

/*
int main() {

	std::set<std::string> nomes = { "Roberto", "Lucas", "Hughs", "Ed", "Ray", "Ana" };

	std::set<std::string> nomes_result;
	for (const auto& nome : nomes) {
		int count = 0;
		for (const auto& letra : nome) {
			if (is_vogal(letra)) {
				count++;
			}
		}
		if (count >= 2) {
			nomes_result.insert(nome);
		}
	}

	std::cout << "Para o conjunto de nomes:" << std::endl;
	print_set(nomes, "", "\n\n");

	std::cout << "Nomes com duas ou mais vogais:" << std::endl;
	print_set(nomes_result, "", "\n");

	return 0;

}
*/