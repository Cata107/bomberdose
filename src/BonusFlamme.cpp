#include "BonusFlamme.h"

//Constructeur
BonusFlamme::BonusFlamme(const sf::Vector2i _coodonnees) : ObjetBonus(_coodonnees)
{
	m_typeObjet = BONUSFLAMME;
}

//Creer le BonusFlamme
bool BonusFlamme::MCreation()
{
	//Ici, Code qui cree le BonusFlamme
	return true;
}

//Augmente la puissance de la bombe du joueur
bool BonusFlamme::MAppliquerEffet(Joueur& _joueur)
{
    return _joueur.MAugmenterPuissance();
}
