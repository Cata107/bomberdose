#ifndef BonusRoller_h
#define BonusRoller_h

//#include "Joueur.h"
#include "ObjetBonus.h"


class BonusRoller : public ObjetBonus {

 public:
	
	/* Constructeur */	BonusRoller(const sf::Vector2i _coordonnees);

		virtual bool	MCreation();
		
		//virtual bool	MAppliquerEffet(Joueur& _joueur);
};

#endif // BonusRoller_h
