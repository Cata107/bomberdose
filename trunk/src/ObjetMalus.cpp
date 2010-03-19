#include "ObjetMalus.h"

//Constructeur
ObjetMalus::ObjetMalus(const sf::Vector2i _coordonnees) : ObjetPrenable(_coordonnees)
{
	m_typeObjet = MALUS;
}

//Creer un objetMalus
bool ObjetMalus::MCreation()
{
	//Ici, code de creation d'un ObjetMalus
	return true;
}

ObjetFixe* ObjetMalus::MClone() const
{
	return new ObjetMalus(*this);
}

//Si un ObjetMalus est touche par une flamme, l'ObjetMalus change de place, sur une Case vide
bool ObjetMalus::MDestruction()
{
    return false;
}

/*
bool ObjetMalus::MAppliquerEffet(Joueur& _joueur)
{
    return _joueur.MRamasserObjet(*this);
}
*/