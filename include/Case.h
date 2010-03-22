#ifndef Case_h
#define Case_h

#include "Macro.h"
#include "ObjetFixe.h"
#include <SFML/System.hpp>

class Case {

 public:

 /*	Constructeur */		Case();

 /* Destructeur */		~Case();

			bool		MCreation();

			bool		MIsEmpty();	//retourne true si la case est vide

			bool		MFill(const ObjetFixe& _objetFixe);	//remplit la Case de l'objet en parametre

			char		MConvertToChar();

			bool		MClean();	//Vider la Case

			bool		MSetPosition(int _indiceCase);	//Fixer la position de la case

			bool		MSetPosition(sf::Vector2i _coordonnees);	//Fixer la position de la case grâce a des coordonnees

	sf::Vector2i		MGetPosition();								//Retourne la position de la case, sous forme de coordonnees

	ObjetFixe*			MGetObjetFixe() const;						//Retourne l'objet que la case contient



 protected:

	sf::Vector2i	m_coordonnees;
	bool			m_vide;			//vrai si la case est vide
	ObjetFixe*		m_pObjetFixe;	//un pointeur vers l'objet contenu
};

#endif // Case_h
