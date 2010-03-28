#ifndef MurCassableAvecObjetPrenable_h
#define MurCassableAvecObjetPrenable_h

#include "MurCassable.h"




class MurCassableAvecObjetPrenable : public MurCassable {

 public:

	/*Constructeur */	MurCassableAvecObjetPrenable(sf::Vector2i _coordonnees);

						MurCassableAvecObjetPrenable(int _typeObjet);

		virtual bool	MCreation();

		ObjetFixe*		MClone() const;

		virtual bool	MDestruction();

		enum ObjetContenu
		{
			MALUS = 0,
			BONUSBOMBE = 1,
			BONUSFLAMME = 2,
			BONUSROLLER = 3,
		};

		ObjetContenu	m_objetContenu;	

protected:
		
			
	
				
				
};

#endif // MurCassableAvecObjetPrenable_h
