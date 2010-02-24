#include "Joueur.h"


//Permet de poser une bombe sur la case où est le joueur
bool Joueur::MPoserBombe(int _puissance)
{
    return false;
}

//Met a jour le joueur après une action
bool Joueur::MUpdate()
{
    return false;
}

//Permet de jouer, c'est-a-dire, bouger ou poser une bombe
bool Joueur::MJouer()
{
    return false;
}

//Retourne le plateau
const Plateau& Joueur::MGetPlateau() const
{
	return m_plateau;
}

//Retourne la position du joueur
const sf::Vector2i Joueur::MGetPosition() const

{
    return m_coordonnees;
}

//Change la position du joueur
bool Joueur::MSetPosition(const sf::Vector2i& _coordonnees)

{
	m_coordonnees.x = _coordonnees.x;
	m_coordonnees.y = _coordonnees.y;
    return true;
}
