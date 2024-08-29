#include "Pingouin.hpp"
#include <iostream>

Pingouin::Pingouin(double vitesseNage, double vitesseMarche, double vitesseGlisse)
    : Aquatique(vitesseNage), Terrestre(vitesseMarche), vitesseGlisse(vitesseGlisse) {}

Pingouin::Pingouin(const Pingouin& autre)
    : Aquatique(autre.vitesseNage), Terrestre(autre.vitesseMarche), vitesseGlisse(autre.vitesseGlisse) {
    std::cout << "Constructeur par copie appele." << std::endl;
}

void Pingouin::nage() const {
    std::cout << "Je nage a une vitesse de " << vitesseNage << " m/s." << std::endl;
}

void Pingouin::marche() const {
    std::cout << "Je marche a une vitesse de " << vitesseMarche << " m/s." << std::endl;
}

void Pingouin::glisse() const {
    std::cout << "Je glisse a une vitesse de " << vitesseGlisse << " m/s." << std::endl;
}

void Pingouin::sePresenter() const {
    std::cout << "Je suis un pingouin. Je peux nager, marcher, et glisser." << std::endl;
}

void Pingouin::setVitesseGlisse(double vitesse) {
    vitesseGlisse = vitesse;
}

double Pingouin::getVitesseGlisse() const {
    return vitesseGlisse;
}
