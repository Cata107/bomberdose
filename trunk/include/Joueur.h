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
    string m_nom;
    int m_nbBombes;
    int m_modificateurVitesse;
    float m_vitesse;
    enum m_maladie
	{
		aucune,
		rapidite,
		lenteur,
		flamme1,
		explosionRapide,
		explosionLente,
		pasDeBombe,
		toucheInversee,
		toujoursBouger,
	};

    struct m_coordonnee
    {
		int x;
		int y;
    };

    Plateau *m_pPlateau;

 public:

    BomberDose *myBomberDose;
};

#endif // Joueur_h
