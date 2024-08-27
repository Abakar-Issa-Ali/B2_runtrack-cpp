#include <iostream>

int findSmallElement(int** tableau, int size) {

    int* smaller = tableau[0];

    for (int i = 1; i < size; ++i) {
        if (*(tableau[i]) < *smaller) {
            smaller = tableau[i];
        }
    }


    return *smaller;
}

int main() {
    int a = 10, b = 22, c = 3, d = 15, e = 8, f = 7;
    int* tableau[] = {&a, &b, &c, &d, &e, &f};
    int size = sizeof(tableau) / sizeof(tableau[0]);

    int smaller = findSmallElement(tableau, size);

    std::cout << "Le plus petit élément du tableau est: " << smaller << std::endl;

    return 0;
}
