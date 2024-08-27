//Écrire un programme en C++ qui permet d'afficher si un nombre entier saisiau clavier est pair ou impair.
#include <iostream>

int main() {
    int number;

    std::cout << "Entrez un nombre entier : ";
    std::cin >> number;

    if (number % 2 == 0) {
        std::cout << number << " est pair." << std::endl;
    } else {
        std::cout << number << " est impair." << std::endl;
    }

    return 0;
}
