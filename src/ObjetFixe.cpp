#include "ObjetFixe.h"

//Constructeur d'un ObjetFixe. Initialise les coordonnees, et met le type de l'objet a false. Les constructeurs des classes filles mettront true a leur type.
ObjetFixe::ObjetFixe(const sf::Vector2i _coordonnees) : m_coordonnees(_coordonnees)
{
	m_typeObjet.bonusBombe = false;
	m_typeObjet.bonusFlamme = false;
	m_typeObjet.bonusRoller = false;
	m_typeObjet.murCassable = false;
	m_typeObjet.murIncassable = false;
	m_typeObjet.flamme = false;
	m_typeObjet.bombe = false;
	m_typeObjet.malus = false;

}

bool ObjetFixe::MIsMurCassable()
{
	return m_typeObjet.murCassable;
}

bool ObjetFixe::MIsMurIncassable()
{
	return m_typeObjet.murIncassable;
}

bool ObjetFixe::MIsBonusFlamme()
{
	return m_typeObjet.bonusFlamme;
}

bool ObjetFixe::MIsBonusBombe()
{
	return m_typeObjet.bonusBombe;
}

bool ObjetFixe::MIsBonusRoller()
{
	return m_typeObjet.bonusRoller;
}