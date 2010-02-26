#include "Joueur.h"

Joueur::Joueur(std::string _nom, sf::Vector2i _coordonnees, Plateau _plateau) : m_nom(_nom), m_coordonnees(_coordonnees), m_score(DEFAUT_SCORE), m_nbBombes(DEFAUT_BOMBE), m_puissance(DEFAUT_PUISSANCE), m_coefficientVitesse(DEFAUT_SPEED), m_maladie(aucune), m_plateau(_plateau)
{

}

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

bool Joueur::MAugmenterNombreBombe()
{
	if (m_nbBombes < MAX_BOMBE)
	{
		m_nbBombes++;
	}
	return true;
}

bool Joueur::MAugmenterPuissance()
{
	if (m_puissance < MAX_PUISSANCE)
	{
		m_puissance++;
	}
	return true;
}

bool Joueur::MAugmenterVitesse()
{
	if (m_coefficientVitesse < MAX_SPEED)
	{
		m_coefficientVitesse++;
	}
	return true;
}