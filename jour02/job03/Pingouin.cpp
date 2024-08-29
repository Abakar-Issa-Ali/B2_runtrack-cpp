#include "Pingouin.hpp"
#include <algorithm>
#include <iostream>


std::vector<std::shared_ptr<Pingouin>> Pingouin::colonie;

Pingouin::Pingouin(double vitesseNage, double vitesseMarche, double vitesseGlisse)
    : Aquatique(vitesseNage), Terrestre(vitesseMarche), vitesseGlisse(vitesseGlisse) {
    colonie.push_back(std::shared_ptr<Pingouin>(this, [](Pingouin*){}));   // Ajout de l'objet courant dans le vecteur colonie
    std::cout << "Pingouin créé et ajouté à la colonie." << std::endl;
}

Pingouin::Pingouin(const Pingouin& autre)
    : Aquatique(autre.vitesseNage), Terrestre(autre.vitesseMarche), vitesseGlisse(autre.vitesseGlisse) {
    colonie.push_back(std::shared_ptr<Pingouin>(this, [](Pingouin*){}));    // Ajout de la copie dans le vecteur colonie
    std::cout << "Pingouin copié et ajouté à la colonie." << std::endl;
}

Pingouin::~Pingouin() {
    
    auto iterator = std::remove_if(colonie.begin(), colonie.end(), // Suppression de l'objet du vecteur colonie
         [this](const std::shared_ptr<Pingouin>& p) { return p.get() == this; });
    colonie.erase(iterator, colonie.end());
    std::cout << "Pingouin détruit et retiré de la colonie." << std::endl;
}

void Pingouin::nage() const {
    std::cout << "Le pingouin nage à une vitesse de " << vitesseNage << " m/s." << std::endl;
}

void Pingouin::marche() const {
    std::cout << "Le pingouin marche à une vitesse de " << vitesseMarche << " m/s." << std::endl;
}

void Pingouin::glisse() const {
    std::cout << "Le pingouin glisse à une vitesse de " << vitesseGlisse << " m/s." << std::endl;
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
