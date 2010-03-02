#include "Joueur.h"

Joueur::Joueur(std::string _nom, sf::Vector2i _coordonneesPixel, Plateau _plateau) : m_nom(_nom), m_coordonneesPixel(_coordonneesPixel), m_score(DEFAUT_SCORE), m_nbBombes(DEFAUT_BOMBE), m_puissance(DEFAUT_PUISSANCE), m_coefficientVitesse(DEFAUT_SPEED), m_maladie(aucune), m_plateau(_plateau), m_nbBombesPosees(0)
{
	m_coordonneesCase = MConvertirPixelEnCase();
}

//Permet de poser une bombe sur la case où est le joueur
bool Joueur::MPoserBombe(int _puissance)
{
	if ((m_nbBombesPosees < m_nbBombes) && (m_plateau.MGetCase(m_coordonneesCase).MIsEmpty()))
    return true;
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
const sf::Vector2i Joueur::MGetPositionPixel() const
{
    return m_coordonneesPixel;
}

const sf::Vector2i Joueur::MGetPositionCase() const
{
	return m_coordonneesCase;
}

const sf::Vector2i Joueur::MConvertirPixelEnCase() const
{
	sf::Vector2i temp;
	temp.x = (m_coordonneesPixel.x / LONGUEUR_CASE ) ;	//A remplacer. LONGUEUR_CASE par le resultat de 1/LONGUEUR_CASE précalcule
	temp.y = (m_coordonneesPixel.y / LARGEUR_CASE ) ;	//A remplacer. LARGEUR_CASE par le resultat de 1/LARGEUR_CASE précalcule
	return temp;
}



//Change la position du joueur
bool Joueur::MSetPosition(const sf::Vector2i& _coordonnees)

{
	m_coordonneesPixel.x = _coordonnees.x;
	m_coordonneesPixel.y = _coordonnees.y;
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