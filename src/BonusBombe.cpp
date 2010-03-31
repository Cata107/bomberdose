#include "BonusBombe.h"

//Constructeur
BonusBombe::BonusBombe(const sf::Vector2i _coodonnees) : ObjetPrenable(_coodonnees)
{
	m_typeObjet = BONUSBOMBE;
}


ObjetFixe* BonusBombe::MClone() const
{
	return new BonusBombe(*this);
}
