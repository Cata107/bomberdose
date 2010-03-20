#include <iostream>
#include <vector>
#include "Plateau.h"
#include "MurCassableAvecObjetPrenable.h"
#include "Macro.h"

int main()
{
	/*
	std::cout << "HELLO" << std::endl ;
	getchar();
	return 1;
	*/
	std::vector<MurCassableAvecObjetPrenable> murs;
	Plateau plateau(murs);
	for (int i = 0; i < NB_CASE; i++)
	{
		if(plateau.MGetCase(i).MIsEmpty())
		{
			std::cout << "Je suis la case (" << plateau.MGetCase(i).MGetPosition().y << ", " << plateau.MGetCase(i).MGetPosition().x << ") et je suis vide !" << std::endl;
		}
		else if (plateau.MGetCase(i).MGetObjetFixe()->MIsMurIncassable())
		{
			std::cout << "Je suis la case (" << plateau.MGetCase(i).MGetPosition().y << ", " << plateau.MGetCase(i).MGetPosition().x << ") et je suis un mur incassable !" << std::endl;
		}
		else if (plateau.MGetCase(i).MGetObjetFixe()->MIsMurCassable())
		{
			std::cout << "Je suis la case (" << plateau.MGetCase(i).MGetPosition().y << ", " << plateau.MGetCase(i).MGetPosition().x << ") et je suis un mur cassable !" << std::endl;
		}

	}
	//getchar();
}
