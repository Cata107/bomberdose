#include "BonusRoller.h"

//Constructeur
BonusRoller::BonusRoller(const sf::Vector2i _coodonnees) : ObjetPrenable(_coodonnees)
{
	m_typeObjet = BONUSROLLER;
}

//Creer le BonusRoller
bool BonusRoller::MCreation()
{
	//Ici, Code qui cree le BonusRoller
	return true;
}

ObjetFixe* BonusRoller::MClone() const
{
	return new BonusRoller(*this);
}

/*
bool BonusRoller::MAppliquerEffet(Joueur& _joueur)
{
    return _joueur.MRamasserObjet(*this);
}
*/