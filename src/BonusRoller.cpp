#include "BonusRoller.h"

//Constructeur
BonusRoller::BonusRoller(const sf::Vector2i _coodonnees) : ObjetPrenable(_coodonnees)
{
	m_typeObjet = BONUSROLLER;
}

ObjetFixe* BonusRoller::MClone() const
{
	return new BonusRoller(*this);
}