#ifndef ObjetFixe_h
#define ObjetFixe_h

#include <SFML/System.hpp>

class ObjetFixe {

 public:

	ObjetFixe(const sf::Vector2i _coordonnees);
    virtual bool MCreation()  = 0;
	virtual bool MIsMurCassable();
	virtual bool MIsMurIncassable();
	virtual bool MIsMalus();
	virtual bool MIsBonusFlamme();
	virtual bool MIsBonusBombe();
	virtual bool MIsBonusRoller();

protected:
	sf::Vector2i m_coordonnees;

	struct TypeObjet
	{
		bool murCassable;
		bool murIncassable;
		bool bonusFlamme;
		bool bonusBombe;
		bool bonusRoller;
		bool bombe;
		bool flamme;
		bool malus;

	};

	TypeObjet m_typeObjet;
};

#endif // ObjetFixe_h
