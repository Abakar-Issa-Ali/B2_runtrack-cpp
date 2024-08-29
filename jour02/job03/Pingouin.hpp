#ifndef PINGOUIN_HPP
#define PINGOUIN_HPP

#include "Aquatique.hpp"
#include "Terrestre.hpp"
#include <vector>
#include <memory>

class Pingouin : public Aquatique, public Terrestre {
private:
    double vitesseGlisse;

public:
    static std::vector<std::shared_ptr<Pingouin>> colonie; // Vecteur statique pour stocker la colonie

    Pingouin(double vitesseNage, double vitesseMarche, double vitesseGlisse);
    Pingouin(const Pingouin& autre);
    virtual ~Pingouin();

    void nage() const override;
    void marche() const override;
    void glisse() const;
    void sePresenter() const;

    void setVitesseGlisse(double vitesse);
    double getVitesseGlisse() const;
};

#endif // PINGOUIN_HPP
