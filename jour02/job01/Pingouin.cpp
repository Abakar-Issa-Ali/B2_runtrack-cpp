#include "Pingouin.hpp"
#include <iostream>

Pingouin::Pingouin(double vitesseNage, double vitesseMarche)
    : Aquatique(vitesseNage), Terrestre(vitesseMarche) {}

void Pingouin::nage() const {
    std::cout << "Le pingouin nage à une vitesse de " << vitesseNage << " m/s." << std::endl;
}

void Pingouin::marche() const {
    std::cout << "Le pingouin marche à une vitesse de " << vitesseMarche << " m/s." << std::endl;
}

void Pingouin::sePresenter() const {
    std::cout << "Je suis un pingouin. Je peux nager et marcher." << std::endl;
}
