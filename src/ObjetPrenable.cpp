#include "ObjetPrenable.h"
#include "Joueur.h"

//Constructeur
ObjetPrenable::ObjetPrenable(const sf::Vector2i _coordonnees) : ObjetFixe(_coordonnees)
{

}


bool ObjetPrenable::MAppliquerEffet(Joueur& _joueur)
{
	return _joueur.MRamasserObjet(this);
}

