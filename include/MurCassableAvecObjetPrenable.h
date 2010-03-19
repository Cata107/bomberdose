#ifndef MurCassableAvecObjetPrenable_h
#define MurCassableAvecObjetPrenable_h

#include "MurCassable.h"


class MurCassableAvecObjetPrenable : public MurCassable {

 public:

	/*Constructeur */	MurCassableAvecObjetPrenable(sf::Vector2i _coordonnees);

		virtual bool	MCreation();

		ObjetFixe*		MClone() const;

		virtual bool	MDestruction();

protected:
		
			enum ObjetContenu
			{
				MALUS,
				BONUSBOMBE,
				BONUSFLAMME,
				BONUSROLLER,
			};

			ObjetContenu m_objetContenu;
				
};

#endif // MurCassableAvecObjetPrenable_h
