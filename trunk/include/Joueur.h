#ifndef Joueur_h
#define Joueur_h

#include "Plateau.h"

class BomberDose;

class Joueur {

 public:

    virtual bool MPoserBombe(int _puissance);

    virtual bool MUpdate();

    virtual bool MJouer();

    virtual Plateau MGetPlateau();

    virtual bool MGetPosition();

    virtual bool MSetPosition(void _coordonnees);

 public:
    int m_score;
    int m_Puissance;

 protected:
    String m_nom;
    int m_nbBombes;
    int m_modificateurVitesse;
    float m_vitesse;
    null m_maladie;
    null m_coordonnee;
    Plateau *m_pPlateau;

 public:

    BomberDose *myBomberDose;
};

#endif // Joueur_h
