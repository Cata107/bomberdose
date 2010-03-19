#include "Flamme.h"

Flamme::Flamme(const sf::Vector2i _coordonnees) : ObjetFixe(_coordonnees)
{
	m_typeObjet = FLAMME;
}

//Creer une Case enflammee, qui tue le joueur
bool Flamme::MCreation()
{
	m_timer.MStartTimer();
    return false;
}

ObjetFixe* Flamme::MClone() const
{
	return new Flamme(*this);
}

//Faire disparaitre la flamme d'une Case
bool Flamme::MDestruction()
{
    return false;
}
