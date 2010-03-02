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

			bool	MFill();

			int		MConvertToInt();

			bool	MClean();

			bool	MSetPosition(int _indiceCase);



 protected:

	sf::Vector2i	m_coordonnees;
	bool			m_vide;
	ObjetFixe*		m_pObjetFixe;
};

#endif // Case_h
