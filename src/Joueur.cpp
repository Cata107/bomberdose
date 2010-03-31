#include "Joueur.h"

Joueur::Joueur(int _indice, sf::Vector2i _coordonneesPixel, Plateau* _plateau) : m_indice(_indice), m_mort(false), m_score(DEFAUT_SCORE), m_nbBombes(DEFAUT_BOMBE), m_puissance(DEFAUT_PUISSANCE), m_coefficientVitesse(DEFAUT_SPEED), m_maladie(aucune), m_plateau(_plateau), m_nbBombesPosees(0)
{
	m_coordonneesPixel.x = _coordonneesPixel.x;
	m_coordonneesPixel.y = _coordonneesPixel.y;
	m_coordonneesCase = MConvertirPixelEnCase();
	MAjusterVitesse();
}

//Permet de poser une bombe sur la case où est le joueur
bool Joueur::MPoserBombe()
{
	if (m_maladie != pasDeBombe)	//si le joueur peut poser des bombe
	{
		if ((m_nbBombesPosees < m_nbBombes) && (m_plateau->MGetCase(m_coordonneesCase)->MIsEmpty()))
		{
			switch (m_maladie)	//on place une bombe sur la case. Le temps de la bombe depend de la maladie qu'il possede
			{
			case (explosionRapide):
				m_plateau->MSetBombe(m_coordonneesCase, m_puissance, m_indice, 1);
				m_nbBombesPosees++;
				break;

			case (explosionLente):
				m_plateau->MSetBombe(m_coordonneesCase, m_puissance, m_indice, 2);
				m_nbBombesPosees++;
				break;
			default:
				m_plateau->MSetBombe(m_coordonneesCase, m_puissance, m_indice);
				m_nbBombesPosees++;
				break;
			}
		}
	}
    return true;
}

bool Joueur::MIsDead()
{
	return m_mort;
}


bool Joueur::MMoveUp()
{
	 
	Case* caseArrivee = m_plateau->MGetCase(sf::Vector2i((m_coordonneesPixel.x * INVERSE_LONGUEUR_CASE), ((m_coordonneesPixel.y-(m_vitesse)) * INVERSE_LARGEUR_CASE)));
	//Si la case d'arrivee est vide OU si la case d'arrivee est la même que celui ou est le joueur
	if (caseArrivee->MIsEmpty() ||  caseArrivee == m_plateau->MGetCase(m_coordonneesCase))
	{
		m_coordonneesPixel.y -= m_vitesse;	//On deplace le joueur
	}
	MAjusterPositionCase();	//On met a jour m_coordonneeCase
	return true;
}

bool Joueur::MMoveDown()
{
	Case* caseArrivee = m_plateau->MGetCase(sf::Vector2i((m_coordonneesPixel.x * INVERSE_LONGUEUR_CASE), ((m_coordonneesPixel.y+m_vitesse) * INVERSE_LARGEUR_CASE)));
	//Si la case d'arrivee est vide OU si la case d'arrivee est la même que celui ou est le joueur
	if (caseArrivee->MIsEmpty() ||  caseArrivee == m_plateau->MGetCase(m_coordonneesCase))
	{
		m_coordonneesPixel.y += m_vitesse;
	}
	MAjusterPositionCase();
	return true;
}

bool Joueur::MMoveLeft()
{
	Case* caseArrivee = m_plateau->MGetCase(sf::Vector2i(((m_coordonneesPixel.x-m_vitesse) * INVERSE_LONGUEUR_CASE), (m_coordonneesPixel.y * INVERSE_LARGEUR_CASE)));
	//Si la case d'arrivee est vide OU si la case d'arrivee est la même que celui ou est le joueur
	if (caseArrivee->MIsEmpty() ||  caseArrivee == m_plateau->MGetCase(m_coordonneesCase))
	{
		m_coordonneesPixel.x -= m_vitesse;
	}
	MAjusterPositionCase();
	return true;
}

bool Joueur::MMoveRight()
{	
	Case* caseArrivee = m_plateau->MGetCase(sf::Vector2i(((m_coordonneesPixel.x+m_vitesse) * INVERSE_LONGUEUR_CASE), (m_coordonneesPixel.y * INVERSE_LARGEUR_CASE)));
	//Si la case d'arrivee est vide OU si la case d'arrivee est la même que celui ou est le joueur
	if (caseArrivee->MIsEmpty() ||  caseArrivee == m_plateau->MGetCase(m_coordonneesCase));
	{
		m_coordonneesPixel.x += m_vitesse;	
	}
	MAjusterPositionCase();
	return true;
}

bool Joueur::MDie()
{
	m_mort = true;
	return true;
}

bool Joueur::MReborn(const sf::Vector2i _coordonnees)
{
	m_mort = false;
	m_coordonneesPixel = _coordonnees;
	return true;
}

bool Joueur::MAugmenterScore()
{
	m_score++;
	return true;
}

unsigned int Joueur::MGetScore()
{
	return m_score;
}
bool Joueur::MSetPlateau(Plateau* _plateau)
{
	m_plateau = _plateau;
	return true;
}


const Plateau* Joueur::MGetPlateau() const
{
	return m_plateau;
}

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
	temp.x = (m_coordonneesPixel.x * INVERSE_LONGUEUR_CASE ) ;	
	temp.y = (m_coordonneesPixel.y * INVERSE_LARGEUR_CASE ) ;	
	return temp;
}

bool Joueur::MRamasserObjet(ObjetPrenable* _objet)
{
	if (m_maladie != aucune)	//Si il y a une maladie
	{
		switch(m_maladie)
		{
			case (rapidite):	//Cas du deplacement rapide
			m_coefficientVitesse = m_tmp;
			m_maladie = aucune;
			MAjusterVitesse();
			break;

			case (lenteur):		//Cas du deplacement lent
			m_coefficientVitesse = m_tmp;
			m_maladie = aucune;
			MAjusterVitesse();
			break;

			case flamme1:		//Cas de la flamme a 1
			m_puissance = m_tmp;
			m_maladie = aucune;
			break;

			case pasDeBombe:	//Cas de l'impossibilite de poser une bombe
			m_maladie = aucune;
			break;

			case explosionRapide:	//Cas de la bombe qui explose rapidement
			m_maladie = aucune;
			break;

			case explosionLente:	//Cas de la bombe qui explose lentement
			m_maladie = aucune;
			break;

			case toucheInversee:
			m_maladie = aucune;
			break;

			case toujoursBouger:
			//code ptet
			m_maladie = aucune;
			break;

			case toujoursPoserBombe:
			//code ptet
			m_maladie = aucune;
			break;
			
		}
	}
	
	//Cas d'un Bonus Bombe
	if (_objet->MIsBonusBombe())	
	{
		if (m_nbBombes < MAX_BOMBE)
			m_nbBombes++;
			m_listBonus.push_back(_objet);
	}
	
	//Cas d'un Bonus Flamme
	if (_objet->MIsBonusFlamme())
	{
		if (m_puissance < MAX_PUISSANCE)
			m_puissance++;
			m_listBonus.push_back(_objet);
	}
	
	//Case d'un Bonus Roller
	if (_objet->MIsBonusRoller())
	{
		if (m_coefficientVitesse < MAX_SPEED)
		{
			m_coefficientVitesse++;
			m_listBonus.push_back(_objet);
		}
		MAjusterVitesse();
	}

	if (_objet->MIsMalus())
	{
		switch(sf::Randomizer::Random(1, NB_MALUS))	//Nombre aleatoire entre 1 et le nombre de Malus
		{
			case 1:
			m_maladie = rapidite;
			m_tmp = m_coefficientVitesse;
			m_coefficientVitesse = MALUS_RAPIDITE;
			MAjusterVitesse();
			break;

			case 2:
			m_maladie = lenteur;
			m_tmp = m_coefficientVitesse;
			m_coefficientVitesse = MALUS_LENTEUR;
			MAjusterVitesse();
			break;

			case 3:
			m_maladie = flamme1;
			m_tmp = m_puissance;
			m_puissance = 1;
			break;

			case 4:
			m_maladie = pasDeBombe;
			break;

			case 5:
			m_maladie = explosionRapide;
			break;

			case 6:
			m_maladie = explosionLente;
			break;
		}
		
	}
	m_plateau->MGetCase(m_coordonneesCase)->MClean();
	return true;
}

//Change la position du joueur
bool Joueur::MSetPosition(const sf::Vector2i& _coordonnees)

{
	m_coordonneesPixel.x = _coordonnees.x;
	m_coordonneesPixel.y = _coordonnees.y;
	MAjusterPositionCase();
    return true;
}

bool Joueur::MAugmenterNombreBombe()
{
	if (m_nbBombes < MAX_BOMBE)
	{
		m_nbBombes++;	//Augmente le nombre de bombe
	}
	return true;
}

bool Joueur::MAugmenterPuissance()
{
	if (m_puissance < MAX_PUISSANCE)
	{
		m_puissance++;	//Augmente la puissance
	}
	return true;
}

bool Joueur::MAugmenterVitesse()
{
	if (m_coefficientVitesse < MAX_SPEED)
	{
		m_coefficientVitesse++;	//Augmente le coefficient de vitesse
	}
	MAjusterVitesse();	//On ajuste la vitesse
	return true;
}

bool Joueur::MDiminuerNbBombesPosees()
{
	m_nbBombesPosees--;	//Quand une bombe explose, diminue le nombre de bombe max
	return true;
}

std::vector<ObjetPrenable*>& Joueur::MGetListBonus()
{
	return m_listBonus;
}

bool Joueur::MAjusterVitesse()
{
	switch(m_coefficientVitesse)	//Ajuste la vitesse selon le coefficient
	{
		case 1:
			m_vitesse = 0;
			break;
		case 2:
			m_vitesse = 1;
			break;
		case 3:
			m_vitesse = 2;
			break;
		case 4:
			m_vitesse = 3;
			break;
		case 5:
			m_vitesse = DEFAUT_SPEED;
			break;
		case 6:
			m_vitesse = 5;
			break;
		case 7:
			m_vitesse = 6;
			break;
		case 8:
			m_vitesse = 7;
			break;
		case 9:
			m_vitesse = 8;
			break;
	}
	return true;
}

bool Joueur::MAjusterPositionCase()
{
	m_coordonneesCase.x = m_coordonneesPixel.x * INVERSE_LONGUEUR_CASE;
	m_coordonneesCase.y = m_coordonneesPixel.y * INVERSE_LARGEUR_CASE;
	return true;
}