#include <iostream>
using namespace std;

void swapValues(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int a = 10, b = 22;
    cout << "Avant l'echange : a = " << a << " b = " << b << endl;
    swapValues(&a, &b);
    cout << "Apres l'echange : a = " << a << " b = " << b << endl;
    return 0;
}