#include "Pingouin.hpp"
#include <iostream>

int main() {
    auto p1 = std::make_shared<Pingouin>("Pingouin1", 2.5, 0.5, 1.2);
    auto p2 = std::make_shared<Pingouin>("Pingouin2", 3.0, 0.7, 1.5);

    p1->sePresenter();
    p2->sePresenter();

    Pingouin::afficherTempsParcours();

    return 0;
}
