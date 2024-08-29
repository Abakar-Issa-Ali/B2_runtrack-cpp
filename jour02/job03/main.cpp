#include "Pingouin.hpp"
#include <iostream>

int main() {
    {
        auto p1 = std::make_shared<Pingouin>(2.5, 0.5, 1.2);
        auto p2 = std::make_shared<Pingouin>(3.0, 0.7, 1.5);

        p1->sePresenter();
        p1->nage();
        p1->marche();
        p1->glisse();

        p2->sePresenter();
        p2->nage();
        p2->marche();
        p2->glisse();

        std::cout << "Nombre de pingouins dans la colonie: " << Pingouin::colonie.size() << std::endl;
    } // Les pingouins sont détruits ici

    std::cout << "Nombre de pingouins dans la colonie après destruction: " << Pingouin::colonie.size() << std::endl;

    return 0;
}
