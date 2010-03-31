#include "Flamme.h"

Flamme::Flamme(const sf::Vector2i _coordonnees) : ObjetFixe(_coordonnees)
{
	m_typeObjet = FLAMME;
	m_pTimer = new Timer();
	m_pTimer->MStartTimer();
}


ObjetFixe* Flamme::MClone() const
{
	return new Flamme(*this);
}
