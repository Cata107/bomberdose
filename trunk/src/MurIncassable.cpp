#include "MurIncassable.h"

//Constructeur
MurIncassable::MurIncassable(sf::Vector2i _coordonnees) : ObjetFixe(_coordonnees)
{
	m_typeObjet = MURINCASSABLE;
}

//Creer un MurIncassable a des endroits fixes
bool MurIncassable::MCreation()
{
    return false;
}

//Un mur ne peut pas etre detruit
bool MurIncassable::MDestruction()
{
    return false;
}