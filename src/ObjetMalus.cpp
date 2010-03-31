#include "ObjetMalus.h"

//Constructeur
ObjetMalus::ObjetMalus(const sf::Vector2i _coordonnees) : ObjetPrenable(_coordonnees)
{
	m_typeObjet = MALUS;
}

ObjetFixe* ObjetMalus::MClone() const
{
	return new ObjetMalus(*this);
}
