#ifndef PINGOUIN_HPP
#define PINGOUIN_HPP

#include "Aquatique.hpp"
#include "Terrestre.hpp"

class Pingouin : public Aquatique, public Terrestre {
public:
    Pingouin(double vitesseNage, double vitesseMarche);
    virtual ~Pingouin() = default;

    void nage() const override;
    void marche() const override;
    void sePresenter() const;
};

#endif // PINGOUIN_HPP
