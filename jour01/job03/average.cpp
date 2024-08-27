#include <iostream>

int main() {
    int sum = 0;
    int number;

    
    for (int i = 0; i < 5; ++i) {
        std::cout << "Entrez un entier: ";
        std::cin >> number;
        sum += number;
    }

    double moyenne = sum / 5.0;
    std::cout << "La moyenne des cinq entiers est: " << moyenne << std::endl;

    return 0;
}
