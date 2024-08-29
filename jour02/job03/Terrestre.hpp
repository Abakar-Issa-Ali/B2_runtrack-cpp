#ifndef TERRESTRE_HPP
#define TERRESTRE_HPP

class Terrestre {
protected:
    double vitesseMarche; 

public:
    Terrestre(double vitesse = 0.0);
    virtual ~Terrestre() = default;

    virtual void marche() const;
    double getVitesseMarche() const;
    void setVitesseMarche(double vitesse);
};

#endif 
