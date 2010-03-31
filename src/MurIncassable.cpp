#include "MurIncassable.h"

//Constructeur
MurIncassable::MurIncassable(sf::Vector2i _coordonnees) : ObjetFixe(_coordonnees)
{
	m_typeObjet = MURINCASSABLE;
}


ObjetFixe* MurIncassable::MClone() const
{
	return new MurIncassable(*this);
}

