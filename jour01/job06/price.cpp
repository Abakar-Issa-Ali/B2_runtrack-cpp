#include <iostream>

int main() {
    double prixHT;
    double kilos;
    double tauxTVA;

    std::cout << "Entrez le prix HT par kilo de carottes (en euros): ";
    std::cin >> prixHT;


    std::cout << "Entrez le nombre de kilos de carottes: ";
    std::cin >> kilos;

    std::cout << "Entrez le taux de TVA (en pourcentage): ";
    std::cin >> tauxTVA;

    double prixTTC = prixHT * kilos * (1 + tauxTVA / 100);

    std::cout << "Le prix TTC de " << kilos << " kilos de carottes est: " << prixTTC << " euros." << std::endl;

    return 0;
}
