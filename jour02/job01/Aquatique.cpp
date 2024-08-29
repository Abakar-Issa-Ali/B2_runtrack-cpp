#include "Aquatique.hpp"
#include <iostream>

Aquatique::Aquatique(double vitesse) : vitesseNage(vitesse) {}

void Aquatique::nage() const {
    std::cout << "L'animal nage à une vitesse de " << vitesseNage << " m/s." << std::endl;
}

double Aquatique::getVitesseNage() const {
    return vitesseNage;
}

void Aquatique::setVitesseNage(double vitesse) {
    vitesseNage = vitesse;
}
