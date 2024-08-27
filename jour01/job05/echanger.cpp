#include <iostream>
using namespace std;
int main() {
    int n, m;

    cout << "Entrez la valeur de n : " << endl;
    cin >> n;

    cout << "Entrez la valeur de m : " << endl;
    cin >> m;

    cout << "Avant l'echange : n = " << n << " m = " << m << endl;

    int temp = n;
    n = m;
    m = temp;
    
    cout << "Apres l'echange : n = " << n << " m = " << m << endl;

    return 0;
}