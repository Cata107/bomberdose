#include "BonusBombe.h"

//Constructeur
BonusBombe::BonusBombe(const sf::Vector2i _coodonnees) : ObjetBonus(_coodonnees)
{
	m_typeObjet = BONUSBOMBE;
}

//Creer le BonusBombe
bool BonusBombe::MCreation()
{
	//Ici, Code qui cree le BonusBombe
	return true;
}

//Augmente le nombre de bombe du joueur
bool BonusBombe::MAppliquerEffet(Joueur& _joueur)
{
    return _joueur.MAugmenterNombreBombe();
}
