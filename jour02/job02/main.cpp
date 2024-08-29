#include "Pingouin.hpp"

int main() {

    Pingouin p(2.5, 0.5, 1.2);      // Création d'un pingouin avec des vitesses spécifiques pour la nage, la marche et la glisse

    p.sePresenter();
    p.nage();
    p.marche();
    p.glisse();


    Pingouin p2 = p;  // Création d'une copie de l'objet p

    p2.sePresenter();
    p2.nage();
    p2.marche();
    p2.glisse();

    return 0;
}
