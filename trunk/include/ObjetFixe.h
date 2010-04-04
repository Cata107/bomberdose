#ifndef ObjetFixe_h
#define ObjetFixe_h

#include <SFML/System.hpp>
#include "Timer.h"

class ObjetFixe {

 public:

	/*Constructeur defaut*/					ObjetFixe();

	/* Constructeur */						ObjetFixe(const sf::Vector2i _coordonnees);

	/* Destructeur */	virtual				~ObjetFixe();

		virtual ObjetFixe*					MClone() const = 0 ;	//Clone l'objet
	
		virtual sf::Vector2i				MGetCoordonnees();	//Retourne les coordonnees de la case ou est l'objet

		virtual Timer*						MGetTimer();		//Timer de l'objet

		virtual bool						MIsMurCassable();	//Retourne vrai si l'objet est un mur cassable

		virtual bool						MIsMurAvecObjet();	//Retourne vrai si l'objet est un mur cassable avec objet
	
		virtual bool						MIsMurIncassable();	//Retourne vrai si l'objet est un mur incassable
	
		virtual bool						MIsMalus();			//Retourne vrai si l'objet est un malus
	
		virtual bool						MIsBonusFlamme();	//Retourne vrai si l'objet est un Bonus Flamme
	
		virtual bool						MIsBonusBombe();	//Retourne vrai si l'objet est un Bonus Bombe
	
		virtual bool						MIsBonusRoller();	//Retourne vrai si l'objet est un Bonus Roller

		virtual bool						MIsBombe();			//Retourne vrai si l'objet est une bombe

		virtual bool						MIsFlamme();		//Retourne vrai si la case est enflammer

		


protected:
		sf::Vector2i	m_coordonnees;	//Les coordonnees de la case ou est l'objet

		enum TypeObjet
		{
						MURCASSABLE,
						MURCASSABLEAVECOBJET,
						MURINCASSABLE,
						BONUSFLAMME,
						BONUSBOMBE,
						BONUSROLLER,
						BOMBE,
						FLAMME,
						MALUS,
		};

		TypeObjet		m_typeObjet;	//Le type de l'objet
		Timer*			m_pTimer;		//Timer de l'objet
};

#endif // ObjetFixe_h
