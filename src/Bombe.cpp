#include "Bombe.h"

	//Constructeur. Appelle le constructeur de la classe ObjetFixe, et appel la methode de creation de bombe.
	Bombe::Bombe(const sf::Vector2i _coordonnees) : ObjetFixe(_coordonnees)
	{
		m_typeObjet = BOMBE;
	}
	
	//Creer la bombe
	bool Bombe::MCreation()
	{	
		m_timer.MStartTimer();
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