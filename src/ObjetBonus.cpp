#include "ObjetBonus.h"

//Constructeur
ObjetBonus::ObjetBonus(const sf::Vector2i _coordonnees) : ObjetPrenable(_coordonnees)
{
}

//Detruit l'ObjetBonus si il est touche par une bombe
bool ObjetBonus::MDestruction()
{
    return false;
}