#include <iostream>

// Fonction template pour afficher un seul argument
template <typename T>
void print(const T& arg) {
    std::cout << arg << std::endl;
}

template <typename T, typename... Args>
void print(const T& first, const Args&... rest) {
    std::cout << first << ", ";
    print(rest...);  // Appel récursif avec les arguments restants
}

int main() {
    
    print(1);
    print(1, 2, 3);
    print("Hello", 42, 3.14);
    print("Un", "Deux", "Trois");

    return 0;
}
