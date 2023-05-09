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
//// Forma est�pida de fazer isso
//void print_vector(std::vector<int> vec) {
//    for (int elem : vec) {
//        std::cout << elem << " ";
//    }
//    std::cout << std::endl;
//}
///*
//// Forma um pouco menos est�pida... se usasse template seria ainda melhor
//// Esta linha define uma fun��o, print_vector, que n�o retorna nenhum valor (palavra-chave void).
//// A fun��o recebe um argumento: uma refer�ncia constante a um objeto std::vector<int>.
//// O const garante que a fun��o n�o possa modificar o vetor passado.
//// A refer�ncia & � usada para evitar a c�pia do vetor ao pass�-lo para a fun��o,
//// tornando a chamada da fun��o mais eficiente.
//void print_vector(const std::vector<int>& vec) {
//    for (int elem : vec) {
//        std::cout << elem << " ";
//    }
//    std::cout << std::endl;
//}
//
//// Uma forma melhor usaria templates.... vamos chegar l�!!!
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
//    std::cout << "Ap�s push_back: ";
//    print_vector(vec);
//
//    // Insere um elemento na posi��o 5
//    vec.insert(vec.begin() + 5, 42);
//    std::cout << "Ap�s insert: ";
//    print_vector(vec);
//
//    // Remove o �ltimo elemento do vetor
//    vec.pop_back();
//    std::cout << "Ap�s pop_back: ";
//    print_vector(vec);
//
//    // Remove o elemento na posi��o 3
//    vec.erase(vec.begin() + 3);
//    std::cout << "Ap�s erase: ";
//    print_vector(vec);
//
//    // Remove todos os elementos do vetor
//    vec.clear();
//    std::cout << "Ap�s clear: ";
//    print_vector(vec);
//
//    // Cria um vetor com 5 elementos, todos com o valor 7
//    std::vector<int> vec2(5, 7);
//    std::cout << "Ap�s criar vetor com 5 elementos (valor 7): ";
//    print_vector(vec2);
//
//    // Redimensiona o vetor para 10 elementos
//    vec2.resize(10);
//    std::cout << "Ap�s resize: ";
//    print_vector(vec2);
//
//    // Cria um gerador de n�meros pseudo aleat�rios
//        // TypeCast expl�cito para evitar warnings
//    unsigned seed = static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
//    /*
//    std::chrono::high_resolution_clock::now(): Esta fun��o est�tica pertence � classe std::chrono::high_resolution_clock e retorna um objeto time_point que representa o tempo atual, medido com a maior resolu��o poss�vel. A classe Std::chrono::high_resolution_clock faz parte da biblioteca <chrono> do C++.
//
//    time_since_epoch(): Este m�todo � chamado no objeto time_point retornado por now(). Ele retorna um objeto duration que representa o tempo decorrido desde um ponto espec�fico no tempo chamado "epoch". O "epoch" � geralmente definido como 00:00:00 UTC, 1� de janeiro de 1970, mas pode variar dependendo da implementa��o.
//
//    count(): Este m�todo � chamado no objeto duration retornado por time_since_epoch(). Ele retorna o n�mero de ticks (unidades de tempo) que comp�em a dura��o. O tipo de retorno e a unidade de tempo dependem da implementa��o e da resolu��o do rel�gio.
//    */
//
//    std::mt19937 generator(seed); // Gerador Mersenne Twister com semente gerada pelo hardware da CPU
//    /*
//    c�digo std::mt19937 generator(seed); cria um objeto chamado generator, que � uma inst�ncia da classe std::mt19937. A classe std::mt19937 � um gerador de n�meros pseudoaleat�rios (PRNG) baseado no algoritmo Mersenne Twister. O gerador � inicializado com uma semente fornecida pelo valor seed.
//
//    A semente (seed) � um valor que determina a sequ�ncia de n�meros gerados pelo gerador de n�meros aleat�rios. Quando um gerador � inicializado com a mesma semente, ele produzir� a mesma sequ�ncia de n�meros. Isso � �til quando voc� deseja gerar a mesma sequ�ncia de n�meros em v�rias execu��es de um programa, por exemplo, para fins de teste ou reprodu��o.
//
//    Neste caso, a vari�vel seed � usada para inicializar o gerador Mersenne Twister.
//    */
//    std::uniform_int_distribution<int> distribution(1, 100); // Distribui��o uniforme entre 1 e 100
//
//    for (size_t i = 0; i < vec2.size(); ++i) {
//        vec2[i] = distribution(generator);
//    }
//
//    std::cout << "Ap�s preencher com valores aleat�rios: ";
//    print_vector(vec2);
//
//    // Ordena o vetor usando a fun��o sort da biblioteca <algorithm>
//    std::sort(vec2.begin(), vec2.end());
//    std::cout << "Ap�s sort: ";
//    print_vector(vec2);
//
//    return 0;
//}
