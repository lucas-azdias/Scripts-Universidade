//// Aula 1 - Classe Vector Completa.cpp 
//// Frank de Alcantara
//// 19-04-2023
////
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <random>
//#include <chrono>
//
//
//// Forma estúpida de fazer isso
//void print_vector(std::vector<int> vec) {
//    for (int elem : vec) {
//        std::cout << elem << " ";
//    }
//    std::cout << std::endl;
//}
///*
//// Forma um pouco menos estúpida... se usasse template seria ainda melhor
//// Esta linha define uma função, print_vector, que não retorna nenhum valor (palavra-chave void).
//// A função recebe um argumento: uma referência constante a um objeto std::vector<int>.
//// O const garante que a função não possa modificar o vetor passado.
//// A referência & é usada para evitar a cópia do vetor ao passá-lo para a função,
//// tornando a chamada da função mais eficiente.
//void print_vector(const std::vector<int>& vec) {
//    for (int elem : vec) {
//        std::cout << elem << " ";
//    }
//    std::cout << std::endl;
//}
//
//// Uma forma melhor usaria templates.... vamos chegar lá!!!
//Template <typename T>
//void print_vector(const std::vector<T>& vec) {
//    for (const T& elem : vec) {
//        std::cout << elem << " ";
//    }
//    std::cout << std::endl;
//}
//*/
//
//int main() {
//    // Cria um vetor vazio
//    std::vector<int> vec;
//
//    // Adiciona elementos ao vetor usando push_back
//    for (int i = 0; i < 10; ++i) {
//        vec.push_back(i);
//    }
//    std::cout << "Após push_back: ";
//    print_vector(vec);
//
//    // Insere um elemento na posição 5
//    vec.insert(vec.begin() + 5, 42);
//    std::cout << "Após insert: ";
//    print_vector(vec);
//
//    // Remove o último elemento do vetor
//    vec.pop_back();
//    std::cout << "Após pop_back: ";
//    print_vector(vec);
//
//    // Remove o elemento na posição 3
//    vec.erase(vec.begin() + 3);
//    std::cout << "Após erase: ";
//    print_vector(vec);
//
//    // Remove todos os elementos do vetor
//    vec.clear();
//    std::cout << "Após clear: ";
//    print_vector(vec);
//
//    // Cria um vetor com 5 elementos, todos com o valor 7
//    std::vector<int> vec2(5, 7);
//    std::cout << "Após criar vetor com 5 elementos (valor 7): ";
//    print_vector(vec2);
//
//    // Redimensiona o vetor para 10 elementos
//    vec2.resize(10);
//    std::cout << "Após resize: ";
//    print_vector(vec2);
//
//    // Cria um gerador de números pseudo aleatórios
//        // TypeCast explícito para evitar warnings
//    unsigned seed = static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
//    /*
//    std::chrono::high_resolution_clock::now(): Esta função estática pertence à classe std::chrono::high_resolution_clock e retorna um objeto time_point que representa o tempo atual, medido com a maior resolução possível. A classe Std::chrono::high_resolution_clock faz parte da biblioteca <chrono> do C++.
//
//    time_since_epoch(): Este método é chamado no objeto time_point retornado por now(). Ele retorna um objeto duration que representa o tempo decorrido desde um ponto específico no tempo chamado "epoch". O "epoch" é geralmente definido como 00:00:00 UTC, 1º de janeiro de 1970, mas pode variar dependendo da implementação.
//
//    count(): Este método é chamado no objeto duration retornado por time_since_epoch(). Ele retorna o número de ticks (unidades de tempo) que compõem a duração. O tipo de retorno e a unidade de tempo dependem da implementação e da resolução do relógio.
//    */
//
//    std::mt19937 generator(seed); // Gerador Mersenne Twister com semente gerada pelo hardware da CPU
//    /*
//    código std::mt19937 generator(seed); cria um objeto chamado generator, que é uma instância da classe std::mt19937. A classe std::mt19937 é um gerador de números pseudoaleatórios (PRNG) baseado no algoritmo Mersenne Twister. O gerador é inicializado com uma semente fornecida pelo valor seed.
//
//    A semente (seed) é um valor que determina a sequência de números gerados pelo gerador de números aleatórios. Quando um gerador é inicializado com a mesma semente, ele produzirá a mesma sequência de números. Isso é útil quando você deseja gerar a mesma sequência de números em várias execuções de um programa, por exemplo, para fins de teste ou reprodução.
//
//    Neste caso, a variável seed é usada para inicializar o gerador Mersenne Twister.
//    */
//    std::uniform_int_distribution<int> distribution(1, 100); // Distribuição uniforme entre 1 e 100
//
//    for (size_t i = 0; i < vec2.size(); ++i) {
//        vec2[i] = distribution(generator);
//    }
//
//    std::cout << "Após preencher com valores aleatórios: ";
//    print_vector(vec2);
//
//    // Ordena o vetor usando a função sort da biblioteca <algorithm>
//    std::sort(vec2.begin(), vec2.end());
//    std::cout << "Após sort: ";
//    print_vector(vec2);
//
//    return 0;
//}
