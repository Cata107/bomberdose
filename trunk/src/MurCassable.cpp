#include "MurCassable.h"

MurCassable::MurCassable(sf::Vector2i _coordonnees) : ObjetFixe(_coordonnees)
{
	m_typeObjet = MURCASSABLE;
}

//Creer un MurCassable 
bool MurCassable::MCreation()
{
    return false;
}