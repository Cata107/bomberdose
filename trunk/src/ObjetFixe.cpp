#include "ObjetFixe.h"

ObjetFixe::ObjetFixe()
{
	
}

//Constructeur d'un ObjetFixe. Initialise les coordonnees, et met le type de l'objet a false. Les constructeurs des classes filles mettront true a leur type.
ObjetFixe::ObjetFixe(const sf::Vector2i _coordonnees) : m_coordonnees(_coordonnees)
{

}


sf::Vector2i ObjetFixe::MGetCoordonnees()
{
	return m_coordonnees;
}

bool ObjetFixe::MIsMurCassable()
{
	return (m_typeObjet == MURCASSABLE);
}

bool ObjetFixe::MIsMurIncassable()
{
	return (m_typeObjet == MURINCASSABLE);
}

bool ObjetFixe::MIsMalus()
{
	return (m_typeObjet == MALUS);
}

bool ObjetFixe::MIsBonusFlamme()
{
	return (m_typeObjet == BONUSFLAMME);
}

bool ObjetFixe::MIsBonusBombe()
{
	return (m_typeObjet == BONUSBOMBE);
}

bool ObjetFixe::MIsBonusRoller()
{
	return (m_typeObjet == BONUSROLLER);
}

