#include "ObjetPrenable.h"

//Constructeur
ObjetPrenable::ObjetPrenable(const sf::Vector2i _coordonnees) : ObjetFixe(_coordonnees)
{
}

//Test la collision entre un joueur et un ObjetPrenable
bool ObjetPrenable::MObjetPris()
{
    return false;
}
