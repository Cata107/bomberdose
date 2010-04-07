#include "BomberDose.h"


BomberDose::BomberDose(int _nbJoueur,int _nbBonusBombe, int _nbBonusFlamme, int _nbBonusRoller, int _nbMalus, int _score, int _temps): m_score(_score)
{
	m_nbJoueur = _nbJoueur;
	m_nbFlamme = _nbBonusFlamme;
	m_nbRoller = _nbBonusRoller;
	m_nbBombe = _nbBonusBombe;
	m_nbMalus = _nbMalus;
	m_nbBonus = _nbBonusBombe + _nbBonusRoller + _nbBonusFlamme + _nbMalus;
	m_temps = _temps * 60;	//Converti le temps passe en parametre, en seconde
	MCreateMursAvecObjet(_nbBonusBombe, _nbBonusFlamme, _nbBonusRoller, _nbMalus);	//On cree la liste de mur avec objet avec les nombres de bonus passe en parametre
	m_pPlateau = new Plateau(m_tPMursCassables, m_nbBonus);	//Creation du plateau
	MCreatePlayer(_nbJoueur);	//Creation des joueurs
	m_pPlateau->MSetJoueurs(m_tPJoueurs);	//On met les joueurs sur le plateau

}


BomberDose::~BomberDose()
{
	//delete m_pPlateau;	//On detruit le plateau

	while (!m_tPJoueurs.empty())	//Tant que la liste de joueur n'est pas vide
	{
		delete m_tPJoueurs.back();	//On detruit le pointeur du joueur
		m_tPJoueurs.pop_back();		//Et on supprime le pointeur detruit de la liste
	}

	while (!m_tPMursCassables.empty())	//Tant que la liste de murs cassable n'est pas vide
	{
		delete m_tPMursCassables.back();	//On detruit le pointeur du mur
		m_tPMursCassables.pop_back();		//Et on supprime le poiteur detruit de la liste
	}
}


//Creer les joueurs et le plateau
bool BomberDose::MCreatePlayer(int _nbJoueur)
{
    for (int i = 0; i < _nbJoueur; i++)	//Pour tout les joueurs
	{
		switch(i)	//On cree le joueur selon leur indice, parce que ca change la position de depart
		{
		case 0:
			m_tPJoueurs.push_back(new Joueur(i+1, sf::Vector2i(ABSCISSE_ORIGINE1, ORDONNEE_ORIGINE1), m_pPlateau));
			break;
		case 1:
			m_tPJoueurs.push_back(new Joueur(i+1, sf::Vector2i(ABSCISSE_ORIGINE2, ORDONNEE_ORIGINE1), m_pPlateau));
			break;

		case 2:
			m_tPJoueurs.push_back(new Joueur(i+1, sf::Vector2i(ABSCISSE_ORIGINE1, ORDONNEE_ORIGINE2), m_pPlateau));
			break;

		case 3:
			m_tPJoueurs.push_back(new Joueur(i+1, sf::Vector2i(ABSCISSE_ORIGINE2, ORDONNEE_ORIGINE2), m_pPlateau));
			break;
		}
	}
	return true;
}

//Recupere le joueur selon son indice
Joueur* BomberDose::MGetJoueur(int _indice)
{
    return m_tPJoueurs[_indice];	//Retourne le joueur d'indice passe en parametre
}

bool BomberDose::MCreateMursAvecObjet(int _nbBonusBombe, int _nbBonusFlamme, int _nbBonusRoller, int _nbMalus)
{
	for (int i = 0; i < _nbMalus; i++)
	{
		m_tPMursCassables.push_back(new MurCassableAvecObjetPrenable(0));
	}

	for (int j = 0; j < _nbBonusBombe; j++)
	{
		m_tPMursCassables.push_back(new MurCassableAvecObjetPrenable(1));
	}

	for (int i = 0; i < _nbBonusFlamme; i++)
	{
		m_tPMursCassables.push_back(new MurCassableAvecObjetPrenable(2));
	}

	for (int j = 0; j < _nbBonusRoller; j++)
	{
		m_tPMursCassables.push_back(new MurCassableAvecObjetPrenable(3));
	}

	return true;
}

bool BomberDose::MRecreerPlateau()
{
	delete m_pPlateau;	//On efface le plateau
	m_tPMursCassables.clear();	//On efface la liste de mur
	MCreateMursAvecObjet(m_nbBombe,m_nbFlamme,m_nbRoller,m_nbMalus);	//Et on recree la liste de mur avec bonus
	m_pPlateau = new Plateau(m_tPMursCassables, m_nbBonus);	//On recree le plateau

	for (unsigned int i = 0; i < m_nbJoueur; i++)	//On replace les joueurs
	{
		m_tPJoueurs[i]->MSetPlateau(m_pPlateau);
		switch (i)
		{
			case 0:
				m_tPJoueurs[i]->MReborn(sf::Vector2i(ABSCISSE_ORIGINE1, ORDONNEE_ORIGINE1));
				break;

			case 1:
				m_tPJoueurs[i]->MReborn(sf::Vector2i(ABSCISSE_ORIGINE2, ORDONNEE_ORIGINE1));
				break;

			case 2:
				m_tPJoueurs[i]->MReborn(sf::Vector2i(ABSCISSE_ORIGINE1, ORDONNEE_ORIGINE2));
				break;

			case 3:
				m_tPJoueurs[i]->MReborn(sf::Vector2i(ABSCISSE_ORIGINE2, ORDONNEE_ORIGINE2));
				break;
		}
		
	}
	return true;
}

int BomberDose::MFinMatch()
{
	int nbVivant = m_nbJoueur;
	if (m_pPlateau->MGetTimer()->MGetTime() > m_temps)	//Si le temps est ecoule
	{
		return 0;	//On retourne 0
	}
	else
	{
		for (unsigned int i = 0; i < m_nbJoueur; i++)
		{
			if (m_tPJoueurs[i]->MIsDead())
			{
				nbVivant--;	
			}
		}
		return nbVivant;	//Sinon, on retourne le nombre de joueur vivant
	}
}

Joueur* BomberDose::MGetGagnant()
{
	int i = 0;
	for (unsigned int j = 0; j < m_nbJoueur; j++)
	{
		if (!m_tPJoueurs[j]->MIsDead())
		{
			i = j;
		}
	}
	return m_tPJoueurs[i];	//Retourne le joueur en vie a la fin d'une partie
}

Plateau* BomberDose::MGetPlateau()
{
	return m_pPlateau;
}

unsigned int BomberDose::MGetScore()
{
	return m_score;
}