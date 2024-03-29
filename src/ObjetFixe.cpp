#include "ObjetFixe.h"

ObjetFixe::ObjetFixe()
{
	m_pTimer = new Timer();
}

ObjetFixe::ObjetFixe(const sf::Vector2i _coordonnees) : m_coordonnees(_coordonnees)
{
	m_pTimer = new Timer();
}

ObjetFixe::~ObjetFixe()
{

}


sf::Vector2i ObjetFixe::MGetCoordonnees()
{
	return m_coordonnees;
}

Timer* ObjetFixe::MGetTimer()
{
	return m_pTimer;
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

bool ObjetFixe::MIsMurAvecObjet()
{
	return (m_typeObjet == MURCASSABLEAVECOBJET);
}

bool ObjetFixe::MIsBombe()
{
	return (m_typeObjet == BOMBE);
}

bool ObjetFixe::MIsFlamme()
{
	return (m_typeObjet==FLAMME);
}