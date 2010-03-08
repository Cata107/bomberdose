#ifndef Case_h
#define Case_h

#include "Macro.h"
#include "ObjetFixe.h"
#include <SFML/System.hpp>

class Case {

 public:

 /*	Constructeur */	Case();

			bool	MCreation();

			bool	MIsEmpty();

			bool	MFill(const ObjetFixe& _objetFixe);

			int		MConvertToInt();

			bool	MClean();

			bool	MSetPosition(int _indiceCase);

			bool	MSetPosition(sf::Vector2i _coordonnees);

	sf::Vector2i	MGetPosition();



 protected:

	sf::Vector2i	m_coordonnees;
	bool			m_vide;
	ObjetFixe*		m_pObjetFixe;
};

#endif // Case_h
