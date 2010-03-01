#ifndef Joueur_h
#define Joueur_h

#include <iostream>
#include <SFML/System.hpp>
#include "Plateau.h"
#include "Macro.h"


class Joueur {

 public:


	Joueur(std::string _nom, sf::Vector2i _coordonnees, Plateau _plateau);
	
    virtual bool MPoserBombe(int _puissance);

    virtual bool MUpdate();

    virtual bool MJouer();

    virtual const Plateau& MGetPlateau() const;

	virtual const sf::Vector2i MGetPositionPixel() const;

	virtual const sf::Vector2i MGetPositionCase() const;

	virtual const sf::Vector2i MConvertirPixelEnCase()const;

	virtual bool MSetPosition(const sf::Vector2i& _coordonnees);
	
	virtual bool MAugmenterNombreBombe();

	virtual bool MAugmenterPuissance();

	virtual bool MAugmenterVitesse();


 protected:
	std::string		m_nom;
	int				m_score;
    int				m_nbBombes;
    int				m_puissance;
	int				m_coefficientVitesse;
    float			m_vitesse;
	int				m_nbBombesPosees;
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
	Maladie			m_maladie;
	sf::Vector2i	m_coordonneesPixel;
	sf::Vector2i	m_coordonneesCase;
    Plateau			m_plateau;

};

#endif // Joueur_h
