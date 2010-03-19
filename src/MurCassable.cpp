#include "MurCassable.h"

MurCassable::MurCassable()
{
	m_typeObjet = MURCASSABLE;
}

MurCassable::MurCassable(sf::Vector2i _coordonnees) : ObjetFixe(_coordonnees)
{
	m_typeObjet = MURCASSABLE;
}

//Creer un MurCassable 
bool MurCassable::MCreation()
{
    return false;
}

ObjetFixe* MurCassable::MClone() const
{
	return new MurCassable(*this);
}

bool MurCassable::MDestruction()
{
	return false;
}

bool MurCassable::MSetCoordonnees(sf::Vector2i _coordonnees)
{
	m_coordonnees = _coordonnees;
	return true;
}