#ifndef MurCassable_h
#define MurCassable_h

#include "ObjetFixe.h"


class MurCassable : public ObjetFixe {

 public:
								MurCassable();

	/*Constructeur */			MurCassable(sf::Vector2i _coordonnees);


		virtual ObjetFixe*		MClone() const;	//Permet de cloner le mur

		virtual bool			MSetCoordonnees(sf::Vector2i _coordonnees);	//Placer le mur aux coordonnees envoyees en parametre
};

#endif // MurCassable_h
