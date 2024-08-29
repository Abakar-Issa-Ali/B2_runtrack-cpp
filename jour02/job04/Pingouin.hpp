#ifndef PINGOUIN_HPP
#define PINGOUIN_HPP

#include "Aquatique.hpp"
#include "Terrestre.hpp"
#include <vector>
#include <memory>
#include <string>

class Pingouin : public Aquatique, public Terrestre {
private:
    double vitesseGlisse;
    std::string nom;

public:
    static std::vector<std::shared_ptr<Pingouin>> colonie; // Vecteur statique pour stocker la colonie

    Pingouin(const std::string& nom, double vitesseNage, double vitesseMarche, double vitesseGlisse);
    Pingouin(const Pingouin& autre);
    virtual ~Pingouin();

    void nage() const override;
    void marche() const override;
    void glisse() const;
    void sePresenter() const;

    double calculerTempsParcours() const;
    static void afficherTempsParcours();

    void setVitesseGlisse(double vitesse);
    double getVitesseGlisse() const;

    std::string getNom() const;
};

#endif // PINGOUIN_HPP
