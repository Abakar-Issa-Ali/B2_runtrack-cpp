#ifndef PINGOUIN_HPP
#define PINGOUIN_HPP

#include "Aquatique.hpp"
#include "Terrestre.hpp"

class Pingouin : public Aquatique, public Terrestre {
private:
    double vitesseGlisse;

public:
    Pingouin(double vitesseNage, double vitesseMarche, double vitesseGlisse);
    Pingouin(const Pingouin& autre);   // Constructeur par copie
    virtual ~Pingouin() = default;

    void nage() const override;
    void marche() const override;
    void glisse() const;              // Nouvelle méthode pour glisser
    void sePresenter() const;

    void setVitesseGlisse(double vitesse);
    double getVitesseGlisse() const;
};

#endif // PINGOUIN_HPP
