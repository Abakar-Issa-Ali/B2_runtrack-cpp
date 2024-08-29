#include "Terrestre.hpp"
#include <iostream>

Terrestre::Terrestre(double vitesse) : vitesseMarche(vitesse) {}

void Terrestre::marche() const {
    std::cout << "L'animal marche à une vitesse de " << vitesseMarche << " m/s." << std::endl;
}

double Terrestre::getVitesseMarche() const {
    return vitesseMarche;
}

void Terrestre::setVitesseMarche(double vitesse) {
    vitesseMarche = vitesse;
}
