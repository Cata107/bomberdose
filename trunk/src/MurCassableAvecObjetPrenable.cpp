#include "MurCassableAvecObjetPrenable.h"

MurCassableAvecObjetPrenable::MurCassableAvecObjetPrenable(sf::Vector2i _coordonnees) : MurCassable(_coordonnees)
{

}

//Creer un MurCassableAvecObjetPrenable
bool MurCassableAvecObjetPrenable::MCreation()
{
    return false;
}

//Une fois detruit, un objet est cree sur la Case ou le mur etait. L'objet depend de la valeur de m_objetContenu
bool MurCassableAvecObjetPrenable::MDestruction()
{
	switch(m_objetContenu)
	{
		case (BONUSBOMBE):
		//Code de la creation de bonus bombe
		break;

		case (BONUSFLAMME):
		//Code Bonus Flamme
		break;

		case (BONUSROLLER):
		//Code Bonus Roller
		break;

		case (MALUS):
		//Code Malus
		break;
	}
    return false;
}