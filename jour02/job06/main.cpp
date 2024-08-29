#include "Pingouin.hpp"
#include <iostream>
# define NOMINMAX
# include <windows.h>

int main() {
    // Création des pingouins
    auto p1 = std::make_shared<Pingouin>("Pingouin1", 2.5, 0.5, 1.2);
    auto p2 = std::make_shared<Pingouin>("Pingouin2", 3.0, 0.7, 1.5);

    p1->sePresenter();
    p1->nage();
    p1->marche();
    p1->glisse();

    p2->sePresenter();
    p2->nage();
    p2->marche();
    p2->glisse();

    Pingouin::afficherTempsParcours();

    // Gestion des lieux de rencontre
    Pingouin::ajouterLieuRencontre("Lac");
    Pingouin::ajouterLieuRencontre("Glacier");
    Pingouin::ajouterLieuRencontre("Banquise");

    Pingouin::afficherLieuxRencontre();

    Pingouin::retirerLieuRencontre("Glacier");

    Pingouin::afficherLieuxRencontre();

    return 0;
}
