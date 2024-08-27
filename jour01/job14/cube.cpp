#include <iostream>

int main() {
    int N;
    int somme = 0;

    std::cout << "Entrez un entier N : ";
    std::cin >> N;

    for (int i = 5; i <= N; ++i) {
        somme += i * i * i;
    }
    std::cout << "La somme des cubes des nombres de 5^3 à N^3 est : " << somme << std::endl;

    return 0;
}