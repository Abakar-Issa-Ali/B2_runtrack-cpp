#include <iostream>
#include <cstdint>

constexpr int fibonacci(int n) {
    return (n <= 1) ? n : (fibonacci(n - 1) + fibonacci(n - 2));
}

bool hasEvenNumberOfOnes(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return (count % 2) == 0;
}

int main() {
    std::cout << "Les dix premiers termes de la suite de Fibonacci sont : " << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;

    unsigned int number = 29;
    std::cout << "Le nombre de bits à 1 dans " << number
     << " est " << (hasEvenNumberOfOnes(number) ? "pair" : "impair") 
     << std::endl;

    return 0;
}
