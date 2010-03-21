#include "MurCassableAvecObjetPrenable.h"

MurCassableAvecObjetPrenable::MurCassableAvecObjetPrenable(sf::Vector2i _coordonnees) : MurCassable(_coordonnees)
{
	
}

MurCassableAvecObjetPrenable::MurCassableAvecObjetPrenable(int _typeObjet)
{
	switch (_typeObjet)
	{
	case 0:
		m_objetContenu = MALUS;
		break;

	case 1:
		m_objetContenu = BONUSBOMBE;
		break;

	case 2:
		m_objetContenu = BONUSFLAMME;
		break;

	case 3:
		m_objetContenu = BONUSROLLER;
		break;
	}
}


//Creer un MurCassableAvecObjetPrenable
bool MurCassableAvecObjetPrenable::MCreation()
{
    return false;
}

ObjetFixe* MurCassableAvecObjetPrenable::MClone() const
{
	return new MurCassableAvecObjetPrenable(*this);
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