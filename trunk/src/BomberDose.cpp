#include "BomberDose.h"


BomberDose::BomberDose(int _nbJoueur,int _nbBonusBombe, int _nbBonusFlamme, int _nbBonusRoller, int _nbMalus, int _score): m_score(_score)
{

	m_nbBonus = _nbBonusBombe + _nbBonusRoller + _nbBonusFlamme + _nbMalus;
	MCreateMursAvecObjet(_nbBonusBombe, _nbBonusFlamme, _nbBonusRoller, _nbMalus);
	m_pPlateau = new Plateau(m_tPMursCassables, m_nbBonus);
	MCreatePlayer(_nbJoueur);
	
}


BomberDose::~BomberDose()
{
	delete m_pPlateau;
	
	while (!m_tPJoueurs.empty())
	{
		delete m_tPJoueurs.back();
		m_tPJoueurs.pop_back();
	}

	while (!m_tPMursCassables.empty())
	{
		delete m_tPMursCassables.back();
		m_tPMursCassables.pop_back();
	}
}


//Creer les joueurs et le plateau
bool BomberDose::MCreatePlayer(int _nbJoueur)
{
    for (int i = 0; i < _nbJoueur; i++)
	{
		switch(i)
		{
		case 0:
			m_tPJoueurs.push_back(new Joueur(i+1, sf::Vector2i(20, 20), m_pPlateau));
			
			break;
		case 1:
			m_tPJoueurs.push_back(new Joueur(i+1, sf::Vector2i(500, 20), m_pPlateau));
			break;
		
		case 2:
			m_tPJoueurs.push_back(new Joueur(i+1, sf::Vector2i(20, 500), m_pPlateau));
			break;

		case 3:
			m_tPJoueurs.push_back(new Joueur(i+1, sf::Vector2i(500, 500), m_pPlateau));
			break;
		}
	}
	return true;
}

//Recupere le joueur selon son indice
Joueur* BomberDose::MGetJoueur(int _indice)
{
    return m_tPJoueurs[_indice];
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
	delete m_pPlateau;
	m_pPlateau = new Plateau(m_tPMursCassables, m_nbBonus);
	
	for (int i = 0; i < m_tPJoueurs.size(); i++)
	{
		m_tPJoueurs[i]->MSetPlateau(m_pPlateau);
	}
	return true;
}

bool BomberDose::MStart()
{

	std::set<int> indiceJoueursPerdant;
	return true;
}
