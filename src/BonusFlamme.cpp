#include "BonusFlamme.h"

//Constructeur
BonusFlamme::BonusFlamme(const sf::Vector2i _coodonnees) : ObjetPrenable(_coodonnees)
{
	m_typeObjet = BONUSFLAMME;
}


ObjetFixe* BonusFlamme::MClone() const
{
	return new BonusFlamme(*this);
}
