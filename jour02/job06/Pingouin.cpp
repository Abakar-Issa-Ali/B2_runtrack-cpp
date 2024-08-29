#include "Pingouin.hpp"
#include <iostream>
#include <algorithm>
#include <windows.h>
#define NOMINMAX

std::vector<std::shared_ptr<Pingouin>> Pingouin::colonie;  // Initialisation du vecteur statique

std::list<std::string> Pingouin::lieuxRencontre;   // Initialisation de la liste statique des lieux de rencontre

Pingouin::Pingouin(const std::string& nom, double vitesseNage, double vitesseMarche, double vitesseGlisse)
    : Aquatique(vitesseNage), Terrestre(vitesseMarche), vitesseGlisse(vitesseGlisse), nom(nom) {
    colonie.push_back(std::shared_ptr<Pingouin>(this, [](Pingouin*){}));
    SetConsoleOutputCP(1252);
    std::cout << "Pingouin '" << nom << "' créé et ajouté à la colonie." << std::endl;

    // Tri du vecteur colonie par temps de parcours
    std::sort(colonie.begin(), colonie.end(),
        [](const std::shared_ptr<Pingouin>& p1, const std::shared_ptr<Pingouin>& p2) {
            return p1->calculerTempsParcours() < p2->calculerTempsParcours();
    });
}

Pingouin::Pingouin(const Pingouin& autre)
    : Aquatique(autre.vitesseNage), Terrestre(autre.vitesseMarche), vitesseGlisse(autre.vitesseGlisse), nom(autre.nom) {
    colonie.push_back(std::shared_ptr<Pingouin>(this, [](Pingouin*){}));
    std::cout << "Pingouin '" << nom << "' copié et ajouté à la colonie." << std::endl;

    // Tri du vecteur colonie par temps de parcours
    std::sort(colonie.begin(), colonie.end(),
        [](const std::shared_ptr<Pingouin>& p1, const std::shared_ptr<Pingouin>& p2) {
            return p1->calculerTempsParcours() < p2->calculerTempsParcours();
        });
}

Pingouin::~Pingouin() {
    auto it = std::remove_if(colonie.begin(), colonie.end(),
            [this](const std::shared_ptr<Pingouin>& p) { return p.get() == this; });
    colonie.erase(it, colonie.end());
    std::cout << "Pingouin '" << nom << "' détruit et retiré de la colonie." << std::endl;

    // Tri du vecteur colonie par temps de parcours après suppression
    std::sort(colonie.begin(), colonie.end(),
    [](const std::shared_ptr<Pingouin>& p1, const std::shared_ptr<Pingouin>& p2) {
        return p1->calculerTempsParcours() < p2->calculerTempsParcours();
    });
}

void Pingouin::nage() const {
    std::cout << "Le pingouin '" << nom << "' nage à une vitesse de " << vitesseNage << " m/s." << std::endl;
}

void Pingouin::marche() const {
    std::cout << "Le pingouin '" << nom << "' marche à une vitesse de " << vitesseMarche << " m/s." << std::endl;
}

void Pingouin::glisse() const {
    std::cout << "Le pingouin '" << nom << "' glisse à une vitesse de " << vitesseGlisse << " m/s." << std::endl;
}

void Pingouin::sePresenter() const {
    std::cout << "Je suis le pingouin '" << nom << "'. Je peux nager, marcher, et glisser." << std::endl;
}

double Pingouin::calculerTempsParcours() const {
    double tempsGlisse = 10.0 / vitesseGlisse;
    double tempsMarche1 = 15.0 / vitesseMarche;
    double tempsNage = 40.0 / vitesseNage;
    double tempsMarche2 = 10.0 / vitesseMarche;
    return tempsGlisse + tempsMarche1 + tempsNage + tempsMarche2;
}

void Pingouin::afficherTempsParcours() {
    for (const auto& pingouin : colonie) {
        std::cout << "Le pingouin '" << pingouin->getNom() << "' met "
        << pingouin->calculerTempsParcours() << " secondes pour parcourir la piste." << std::endl;
    }
}

void Pingouin::ajouterLieuRencontre(const std::string& lieu) {
    lieuxRencontre.push_back(lieu);
    std::cout << "Lieu de rencontre '" << lieu << "' ajouté." << std::endl;
}

void Pingouin::retirerLieuRencontre(const std::string& lieu) {
    lieuxRencontre.remove(lieu);
    std::cout << "Lieu de rencontre '" << lieu << "' retiré." << std::endl;
}

void Pingouin::afficherLieuxRencontre() {
    std::cout << "Lieux de rencontre des pingouins :" << std::endl;
    for (const auto& lieu : lieuxRencontre) {
        std::cout << "- " << lieu << std::endl;
    }
}

void Pingouin::setVitesseGlisse(double vitesse) {
    vitesseGlisse = vitesse;
}

double Pingouin::getVitesseGlisse() const {
    return vitesseGlisse;
}

std::string Pingouin::getNom() const {
    return nom;
}
