#include <iostream>


int doubleArray(int* tableau, int size) {
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        *(tableau + i) *= 2;
        sum += *(tableau + i);
    }

    return sum;
}

void printArray(int* tableau, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << *(tableau + i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int tableau[] = {1, 2, 3, 4, 5};
    int size = sizeof(tableau) / sizeof(tableau[0]);

    int sum = doubleArray(tableau, size);

    std::cout << "Tableau après avoir doublé les éléments: ";
    printArray(tableau, size);

    std::cout << "La somme des éléments doublés est: " << sum << std::endl;

    return 0;
}
