#include "Plateau.h"

Plateau::Plateau()
{
	m_tCase = new Case[NB_CASE];
	
	for (int i = 0; i < NB_CASE; i++)
	{
		m_tCase[i].MSetPosition(i);
	}
}

//Creer le Plateau
bool Plateau::MCreation(MurCassableAvecObjetPrenable _listeMurCassableAvecObjetPrenable)
{
    return false;
}

//Destruction du Plateau
bool Plateau::MDestruction()
{
    return false;
}

//Place une bombe a la case aux coordonnees passees en parametre
bool Plateau::MSetBombe(sf::Vector2i _coordonnees)
{
	m_listBombes.push_back(new Bombe(_coordonnees));
    return true;
}

//Place les MursIncassables, qui sont fixes
bool Plateau::MPlacerMursIncassables()
{
	MPlacerMursIncassablesBord();
	MPlacerMursIncassablesMilieu();
    return true;
}

//Place les murs incassables ds bords
bool Plateau::MPlacerMursIncassablesBord()
{
	//On remplit d'abord le bord haut
	for (int i = 0; i < NB_COLONNES; i++)
	{
		m_tCase[i].MFill(MurIncassable(m_tCase[i].MGetPosition()));
	}
	//Puis on remplit le bord gauche et droit
	for (int j = NB_COLONNES; j < (NB_LIGNES-1)*NB_COLONNES; j += NB_COLONNES) //On parcourt chaque ligne, et on met sur la 1ere et la derniere colonne
	{
		m_tCase[j].MFill(MurIncassable(m_tCase[j].MGetPosition()));
		m_tCase[j + NB_COLONNES - 1 ].MFill(MurIncassable(m_tCase[j + NB_COLONNES - 1].MGetPosition()));
	}
	//Enfin, on remplit le bord bas
	for (int k = (NB_LIGNES-1)*NB_COLONNES; k < NB_CASE; k++)
	{
		m_tCase[k].MFill(MurIncassable(m_tCase[k].MGetPosition()));
	}

	return true;
}

//Place les murs incassables au milieu
bool Plateau::MPlacerMursIncassablesMilieu()
{
	for (int i = 2; i < NB_COLONNES-1; i += 2)
	{
		for (int j = 2; j <NB_LIGNES-1; j += 2)
		{
			int indice = (j*NB_COLONNES) + i;
			m_tCase[indice].MFill(MurIncassable(m_tCase[indice].MGetPosition()));
		}
	}
	return true;
}

//Place les MursCassables, aleatoirement, sauf sur certaines Cases interdites
bool Plateau::MPlacerMursCassables(MurCassableAvecObjetPrenable _listMurCassableAvecObjetPrenable)
{
    return false;
}

//Retourne une case du plateau, selon les coordonnees donnees en parametre
Case Plateau::MGetCase(sf::Vector2i _coordonnees)
{
    int accesColonne = _coordonnees.x;
    int accesLigne = _coordonnees.y * NB_COLONNES;
    int coordUniDimensionnelle = accesColonne + accesLigne;

    return m_tCase[ coordUniDimensionnelle ];
}

Case Plateau::MGetCase(int _coordonneeUniDimensionnelle)
{
    return m_tCase[ _coordonneeUniDimensionnelle ];
}

//Retourne le Plateau
Case Plateau::MGetPlateau()

{
	return *m_tCase;
}

int* Plateau::MGetPlateauConverti()
{
    int* tableau = new int[NB_LIGNES*NB_COLONNES];
    for (int i = 0; i < NB_LIGNES*NB_COLONNES; i++)
    {
        tableau[i] = Plateau::MGetCase(i).MConvertToInt();
    }
    return tableau;
}
