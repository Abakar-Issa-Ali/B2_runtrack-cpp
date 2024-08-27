#include <iostream>

int main() {
    int nombre, inverse = 0;


    std::cout << "Entrez un nombre: ";
    std::cin >> nombre;

    while (nombre != 0) {
        int chiffre = nombre % 10;
        inverse = inverse * 10 + chiffre;
        nombre /= 10;
    }

    std::cout << "Le nombre inversé est: " << inverse << std::endl;

    return 0;
}
