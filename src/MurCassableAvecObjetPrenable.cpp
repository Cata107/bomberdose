#include "MurCassableAvecObjetPrenable.h"

MurCassableAvecObjetPrenable::MurCassableAvecObjetPrenable(sf::Vector2i _coordonnees) : MurCassable(_coordonnees)
{

}

//Creer un MurCassableAvecObjetPrenable
bool MurCassableAvecObjetPrenable::MCreation()
{
    return false;
}

//Une fois detruit, un objet est cree sur la Case ou le mur etait 
bool MurCassableAvecObjetPrenable::MDestruction()
{
    return false;
}