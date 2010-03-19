#include "BonusFlamme.h"

//Constructeur
BonusFlamme::BonusFlamme(const sf::Vector2i _coodonnees) : ObjetPrenable(_coodonnees)
{
	m_typeObjet = BONUSFLAMME;
}

//Creer le BonusFlamme
bool BonusFlamme::MCreation()
{
	//Ici, Code qui cree le BonusFlamme
	return true;
}

ObjetFixe* BonusFlamme::MClone() const
{
	return new BonusFlamme(*this);
}

/*
bool BonusFlamme::MAppliquerEffet(Joueur& _joueur)
{
    return _joueur.MRamasserObjet(*this);
}
*/