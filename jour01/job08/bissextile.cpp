#include <iostream>

int main() {
    int annee;

    std::cout << "Entrez une annee : ";
    std::cin >> annee;

    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        std::cout << annee << " est une année bissextile." << std::endl;
    } else {
        std::cout << annee << " n'est pas une année bissextile." << std::endl;
    }

    return 0;
}