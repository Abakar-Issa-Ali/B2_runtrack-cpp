#include <iostream>

// Template de fonction max
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int a = 10;
    int b = 20;
    std::cout << "Max entre " << a << " et " << b << " est: " << max(a, b) << std::endl;

    double c = 5.5;
    double d = 2.3;
    std::cout << "Max entre " << c << " et " << d << " est: " << max(c, d) << std::endl;

    char e = 'a';
    char f = 'z';
    std::cout << "Max entre " << e << " et " << f << " est: " << max(e, f) << std::endl;

    return 0;
}
