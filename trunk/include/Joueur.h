#ifndef Joueur_h
#define Joueur_h

#include <iostream>
#include <SFML/System.hpp>
#include "Plateau.h"


class Joueur {

 public:

    virtual bool MPoserBombe(int _puissance);

    virtual bool MUpdate();

    virtual bool MJouer();

    virtual const Plateau& MGetPlateau() const;

	virtual const sf::Vector2i MGetPosition() const;

	virtual bool MSetPosition(const sf::Vector2i& _coordonnees);


 protected:
	std::string m_nom;
	int m_score;
    int m_nbBombes;
    int m_Puissance;
	int m_modificateurVitesse;
    float m_vitesse;
    enum Maladie
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
	Maladie m_maladie;
	sf::Vector2i m_coordonnees;

    Plateau m_plateau;

};

#endif // Joueur_h
