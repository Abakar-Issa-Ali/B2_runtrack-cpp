#ifndef PINGOUIN_HPP
#define PINGOUIN_HPP

#include "Aquatique.hpp"
#include "Terrestre.hpp"
#include <vector>
#include <memory>
#include <string>
#include <list>  // Pour utiliser std::list

class Pingouin : public Aquatique, public Terrestre {
private:
    double vitesseGlisse;
    std::string nom;

public:
    static std::vector<std::shared_ptr<Pingouin>> colonie;    // Vecteur statique pour stocker la colonie
    static std::list<std::string> lieuxRencontre;    // Liste statique pour stocker les lieux de rencontre

    Pingouin(const std::string& nom, double vitesseNage, double vitesseMarche, double vitesseGlisse);
    Pingouin(const Pingouin& autre);
    virtual ~Pingouin();

    void nage() const override;
    void marche() const override;
    void glisse() const;
    void sePresenter() const;

    double calculerTempsParcours() const;
    static void afficherTempsParcours();

    static void ajouterLieuRencontre(const std::string& lieu);
    static void retirerLieuRencontre(const std::string& lieu);
    static void afficherLieuxRencontre();

    void setVitesseGlisse(double vitesse);
    double getVitesseGlisse() const;

    std::string getNom() const;
};

#endif // PINGOUIN_HPP
