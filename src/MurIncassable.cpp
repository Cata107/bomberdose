#include "MurIncassable.h"

//Constructeur
MurIncassable::MurIncassable(sf::Vector2i _coordonnees) : Mur(_coordonnees)
{
	m_typeObjet.murIncassable = true;
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
