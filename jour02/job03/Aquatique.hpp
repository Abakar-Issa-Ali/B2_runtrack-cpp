#ifndef AQUATIQUE_HPP
#define AQUATIQUE_HPP

class Aquatique {
protected:
    double vitesseNage;

public:
    Aquatique(double vitesse = 0.0);
    virtual ~Aquatique() = default;

    virtual void nage() const;
    double getVitesseNage() const;
    void setVitesseNage(double vitesse);
};

#endif // AQUATIQUE_HPP
