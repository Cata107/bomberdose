#include <iostream>
#include <vector>
#include "Plateau.h"
#include "MurCassableAvecObjetPrenable.h"
#include "Macro.h"
#include "BomberDose.h"
/*
int main()
{
	/*
	std::cout << "HELLO" << std::endl ;
	getchar();
	return 1;
	*/

	/*
	std::vector<MurCassableAvecObjetPrenable*> murs;
	Plateau* plateau = new Plateau(murs, 0);
	for (int i = 0; i < NB_CASE; i++)
	{
		if(plateau->MGetCase(i)->MIsEmpty())
		{
			std::cout << "Je suis la case (" << plateau->MGetCase(i)->MGetPosition().y << ", " << plateau->MGetCase(i)->MGetPosition().x << ") et je suis vide !" << std::endl;
		}
		else if (plateau->MGetCase(i)->MGetObjetFixe()->MIsMurIncassable())
		{
			std::cout << "Je suis la case (" << plateau->MGetCase(i)->MGetPosition().y << ", " << plateau->MGetCase(i)->MGetPosition().x << ") et je suis un mur incassable !" << std::endl;
		}
		else if (plateau->MGetCase(i)->MGetObjetFixe()->MIsMurCassable())
		{
			std::cout << "Je suis la case (" << plateau->MGetCase(i)->MGetPosition().y << ", " << plateau->MGetCase(i)->MGetPosition().x << ") et je suis un mur cassable !" << std::endl;
		}

	}

	delete plateau;
	getchar();
	*//*
	BomberDose* bomberdose = new BomberDose(4, 8, 8, 8, 3, 5, 5);
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Je suis le joueur numero" << i+1 << " et je suis a la position (" << bomberdose->m_tPJoueurs[i]->MGetPositionPixel().y << ", " << bomberdose->m_tPJoueurs[i]->MGetPositionPixel().x << ")." << std::endl;
	}
//	getchar();
}
*/
