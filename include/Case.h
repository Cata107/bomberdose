#ifndef Case_h
#define Case_h
#include "Macro.h"

#include "ObjetFixe.h"
#include <SFML/System.hpp>

class Case {

 public:

    virtual bool MCreation();

    virtual bool MIsEmpty();

    virtual bool MFill();

    int MConvertToInt();

	virtual bool MClean();



 protected:

	sf::Vector2i m_coordonnees;
	bool m_vide;
	ObjetFixe* m_pObjetFixe;
};

#endif // Case_h
