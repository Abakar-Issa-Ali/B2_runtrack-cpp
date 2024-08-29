#ifndef TERRESTRE_HPP
#define TERRESTRE_HPP

class Terrestre {
protected:
    double vitesseMarche; // Vitesse de marche en m/s

public:
    Terrestre(double vitesse = 0.0);
    virtual ~Terrestre() = default;

    virtual void marche() const;
    double getVitesseMarche() const;
    void setVitesseMarche(double vitesse);
};

#endif // TERRESTRE_HPP
