#include "Bombe.h"

	//Constructeur. Appelle le constructeur de la classe ObjetFixe, et appel la methode de creation de bombe.
	Bombe::Bombe(const sf::Vector2i _coordonnees,int _puissance, int _indiceJoueur, int _maladie) : ObjetFixe(_coordonnees), m_puissance(_puissance), m_indiceJoueur(_indiceJoueur), m_maladie(_maladie)
	{
		m_typeObjet = BOMBE;	//On met le type de l'objet a la valeur BOMBE
		m_pTimer = new Timer();
		m_pTimer->MStartTimer();	//On demarre le timer
	}

	Bombe::~Bombe()
	{

	}

/*	bool Bombe::operator==(const Bombe &_bombe)
	{
		if (m_coordonnees == _bombe.m_coordonnees)
		{
			return true;
		}
		else
		{
			return false;
		}
	}*/

	ObjetFixe* Bombe::MClone() const
	{
		return new Bombe(*this);
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
