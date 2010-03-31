#include "MurCassableAvecObjetPrenable.h"

MurCassableAvecObjetPrenable::MurCassableAvecObjetPrenable(sf::Vector2i _coordonnees) : MurCassable(_coordonnees)
{
	m_typeObjet = MURCASSABLEAVECOBJET;
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
	m_typeObjet = MURCASSABLEAVECOBJET;
}



ObjetFixe* MurCassableAvecObjetPrenable::MClone() const
{
	return new MurCassableAvecObjetPrenable(*this);
}
