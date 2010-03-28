#include "Bombe.h"

	//Constructeur. Appelle le constructeur de la classe ObjetFixe, et appel la methode de creation de bombe.
	Bombe::Bombe(const sf::Vector2i _coordonnees,int _puissance, int _indiceJoueur, int _maladie) : ObjetFixe(_coordonnees), m_puissance(_puissance), m_indiceJoueur(_indiceJoueur), m_maladie(_maladie)
	{
		m_typeObjet = BOMBE;
	}

	Bombe::~Bombe()
	{
		
	}
	
	//Creer la bombe
	bool Bombe::MCreation()
	{	
		m_pTimer->MStartTimer();
		return true;
	}

	ObjetFixe* Bombe::MClone() const
	{
		return new Bombe(*this);
	}
	
	//Detruit la bombe
	bool Bombe::MDestruction()
	{
		return false;
	}

	int Bombe::MGetPuissance()
	{
		return m_puissance;
	}

	int Bombe::MGetIndice()
	{
		return m_indiceJoueur;
	}

	int Bombe::MGetMaladie()
	{
		return m_maladie;
	}