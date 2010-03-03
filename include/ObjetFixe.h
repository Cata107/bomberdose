#ifndef ObjetFixe_h
#define ObjetFixe_h

#include <SFML/System.hpp>

class ObjetFixe {

 public:

	/* Constructeur */	ObjetFixe(const sf::Vector2i _coordonnees);
		
		virtual bool			MCreation()  = 0;
	
		virtual sf::Vector2i	MGetCoordonnees();

		virtual bool			MIsMurCassable();
	
		virtual bool			MIsMurIncassable();
	
		virtual bool			MIsMalus();
	
		virtual bool			MIsBonusFlamme();
	
		virtual bool			MIsBonusBombe();
	
		virtual bool			MIsBonusRoller();

		


protected:
		sf::Vector2i	m_coordonnees;

		enum TypeObjet
		{
						MURCASSABLE,
						MURINCASSABLE,
						BONUSFLAMME,
						BONUSBOMBE,
						BONUSROLLER,
						BOMBE,
						FLAMME,
						MALUS,
		};

		TypeObjet		m_typeObjet;
};

#endif // ObjetFixe_h
