#include "BonusRoller.h"

//Constructeur
BonusRoller::BonusRoller(const sf::Vector2i _coodonnees) : ObjetBonus(_coodonnees)
{
	m_typeObjet = BONUSROLLER;
}

//Creer le BonusRoller
bool BonusRoller::MCreation()
{
	//Ici, Code qui cree le BonusRoller
	return true;
}

//Augmnte la vitesse du joueur
bool BonusRoller::MAppliquerEffet(Joueur& _joueur)
{
    return _joueur.MAugmenterVitesse();
}
